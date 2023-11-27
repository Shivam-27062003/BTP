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
	try:
		index = cindex.Index.create()
		translation_unit = index.parse(code_file)
		ast = translation_unit.cursor
		return ast
	except:
		print(Custom_Error("AST creation failed"))

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
		elif flag == True and  depth>1 \
				and ast_node.kind==cindex.CursorKind.VAR_DECL:
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
			line2+= '{}={};\n'.format(y,x)
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
	loop_pattern = r'(?:for|while|do)\s*\([^)]*\)\s*\{([^}]+)\}'
	matches = re.finditer(loop_pattern, code)
	for match in matches:
		loop_content = match.group(1)
		temp = loop_content
		modified_loop_content =temp + '\n' +  code_chunk
		code = code.replace(loop_content, modified_loop_content)
	return code


if __name__ == "__main__":
	filepath: str = None
	if len(sys.argv) > 1:
		filepath = sys.argv[1]
	ast = create_ast(filepath)
	variables = []
	extract_variables(ast,variables,False)
	with open(filepath,'r') as file1:
		code = file1.read()
	code = insert_declarations(code,variables)
	code_chunk = create_code_chunk_CPROVER_assert(variables)
	code = find_loop_pattern(code,code_chunk)
	print(code)
	# with open(filepath, 'w') as new_file:
	# 	new_file.write(code)
                           