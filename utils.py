from clang import cindex
import sys,re

'''
	declaration of custom exception used in the project
'''

class Custom_Error(Exception):
	def __init__(self, value):
		self.value = value 
	def __str__(self):
		return(repr(self.value))

'''
	create abstract syntax tree for the given code
'''

def create_ast(code_file):
	# try:
	index = cindex.Index.create()
	translation_unit = index.parse(code_file)
	ast = translation_unit.cursor
	return ast
	# except:
		# print(Custom_Error("AST creation failed"))

'''
	extract global variables and the main function's 
	local variable for AST
'''

def extract_variables(ast_node: any,variables: list
					  ,flag: bool,depth = 0) -> None:
	try:
		if ast_node.kind == cindex.CursorKind.VAR_DECL \
							and depth==1 and flag==False:
			variables.append((ast_node.type.spelling,
							ast_node.spelling))
		elif ast_node.kind == cindex.CursorKind.FUNCTION_DECL \
								and ast_node.spelling == 'main':
				flag = True
		elif ast_node.kind==cindex.CursorKind.VAR_DECL \
							and flag == True and  depth>1:
				variables.append((ast_node.type.spelling,
								ast_node.spelling))
		for child_node in ast_node.get_children():
				extract_variables(child_node,variables,flag,depth + 1)
	except:
		print(Custom_Error("Variable Extraction from AST failed"))

'''
	insert the declarations of artificial variables 
	for the use of CRPOVER and return the updated code 
'''

def insert_declarations(code: str,variables: list) -> str:
		for vars in variables:
			var_type = vars[0]
			var_name = vars[1]
			vars = "{} o_{};".format(var_type,var_name)
			code  = vars + '\n' + code
		return code

'''
	create the code_chunk that need to be insterted
	in the original code for the purpose of running 
	CPORVER 
'''

def create_code_chunk_CPROVER_assert(variables: list) -> str:
	try:
		original_variables = []
		artificial_variables = []
		for vars in variables:
			var_name = vars[1]
			artificial_variables.append('o_' + var_name)
			original_variables.append(var_name)
		line1 = '__CPROVER_assert(!(' 
		for i in range(len(artificial_variables)):
			x = artificial_variables[i]
			y = original_variables[i]
			temp = '{}=={}'.format(x,y)
			line1+=temp
			if i!=len(artificial_variables)-1:
				line1+=' && '
		line1+='),"OK");'
		line2 = ''
		for i in range(len(artificial_variables)):
			x = artificial_variables[i]
			y = original_variables[i]
			line2+= '{}={};\n'.format(x,y)
		code_chunk = line1 + '\n' + line2
		return code_chunk
	except:
		print(Custom_Error("Code chunk creation failed"))

'''
	find the location where code_chunk needs to be 
	inserted in the original code file using regex
	matching and insert the code_chunk to create a 
	new code chunk
'''

def create_code_chunk_CPROVER_assume(code):
	loop_pattern = r'(?:for|while|do)\s*\([^)]*\)\s*\{([^}]+)\}'
	matches = re.finditer(loop_pattern, code)
	for match in matches:
		loop_content = match.group(1)
		temp = loop_content
		modified_loop_content = '    __CPROVER__assume(!(a==b));\n' + temp
		code = code.replace(loop_content, modified_loop_content)
	return code


def find_loop_pattern(code,code_chunk):
	loop_pattern = re.compile(r'while\s*\([^)]*\)\s*{([^{}]*(?:{[^{}]*}[^{}]*)*)}')
	matches = re.finditer(loop_pattern, code)
	for match in matches:
		loop_content = match.group(1)
		temp = loop_content
		modified_loop_content =temp + '\n' +  code_chunk
		code = code.replace(loop_content, modified_loop_content)
		break
	loop_pattern = re.compile(r'do\s*{([^{}]*(?:{[^{}]*}[^{}]*)*)}\s*while\s*\([^)]*\);')
	matches = re.finditer(loop_pattern, code)
	for match in matches:
		loop_content = match.group(1)
		print(loop_content)
		temp = loop_content
		modified_loop_content =temp + '\n' +  code_chunk
		code = code.replace(loop_content, modified_loop_content)
		break
	return code

def trace_extraction(tracefile):
	with open(tracefile,'r') as file:
		trace = file.read()
	trace = re.sub(r'^.*==.*$', '', trace, flags=re.MULTILINE)
	assignment_lines = re.findall(r'(.+?)\s*=\s*(-?\d+)([^=])', trace)
	unique_vars: dict = {}
	for line in assignment_lines:
		arr = []
		for word in line:
			temp  = ''
			for c in word:
				if c == ' ':
					continue
				temp += c
			arr.append(temp)
		x = ''
		for i in range(1,len(arr)):
			x += arr[i]
		unique_vars[arr[0]] = int(x)
	variables_with_values = {}
	for x,y in unique_vars.items():
		if x[0] == 'o' and x[1] == '_':
			continue
		variables_with_values[x] = y
	return variables_with_values

def create_code_chunk_CPROVER_assume(code,variables,variables_values_extracted_from_trace):
	temp = ''
	for variable in variables:
		if variable[1] not in variables_values_extracted_from_trace:
			continue
		if variable[1][0] =='o' and variable[1][1] =='_':
			continue
		if temp!='':
			temp += ' && '
		temp += variable[1] +'=='+ str(variables_values_extracted_from_trace[variable[1]])
	if temp!='':
		code_chunk = '__CPROVER_assume(!(' + temp + '));\n'
		pattern = r'(__CPROVER_assert\(.*\);)'
		modified_code = re.sub(pattern, code_chunk + '\n\\1', code)
		return modified_code
	
def all_zero_heuristic(trace,varibles):
	patches = []
	patch = ''
	ans = False
	for x in trace:
		all_zero = True
		for y in trace[x]:
			if y!=0:
				all_zero = False
		if(all_zero and x in varibles):
			patch = f'{x}!=0'
			patches.append(patch)
			ans = True
	return (ans,patches)

def all_negative_heuristic(trace,variables):
	patches = []
	patch = ''
	ans = False
	for x in trace:
		all_negative = True
		for y in trace[x]:
			if y>=0:
				all_negative= False
		if(all_negative and x in variables):
			patch = f'{x}>=0'
			patches.append(patch)
			ans = True
	return (ans,patches)

def generate_patch(trace,variables):
	variables_list = []
	for x,y in variables:
		variables_list.append(y)
	ans,patch = all_zero_heuristic(trace,variables_list)
	if ans==True:
		return patch
	ans,patch = all_negative_heuristic(trace,variables_list)
	if ans==True:
		return patch