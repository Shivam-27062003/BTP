import sys,re
from Function_Var import AST

class Injector:
	def __init__(self) -> None:
		self.ast = AST()
		self.loop_pattern = r'(?:for|while|do)\s*\([^)]*\)\s*\{([^}]+)\}'
		self.loop_begin_pattern = r'(while|for)\s*\([^)]*\)(?=\s*\{)?'

	def inject(self,filepath):
		variables = self.ast.get_variables(filepath)
		artificial_variables = []
		for vars in variables:
			var_type = vars[0]
			var_name = vars[1]
			vars = "{} o_{};".format(var_type,var_name)
			code  = vars + '\n' + code
			artificial_variables.append((var_name,'o_'+var_name))

		code_line_1 = '__CPROVER_assert(!(' 
		for i in range(len(artificial_variables)):
			x = artificial_variables[i][0]
			y = artificial_variables[i][1]
			temp = '{}=={}'.format(x,y)
			code_line_1+=temp
			if i!=len(artificial_variables)-1:
				code_line_1+=' && '
		code_line_1+='),"OK");'
		code_line_2 = ''
		for x,y in artificial_variables:
			code_line_2+= '{}={};\n'.format(y,x)
		code_chunk = code_line_1 + '\n' + code_line_2
	
	def find_pattern(self,filepath,code_chunk,loop_pattern):
		matches = re.finditer(self.loop_pattern, code)
		for match in matches:
			loop_content = match.group(1)
			temp = loop_content
			modified_loop_content =temp + '\n' +  code_chunk
			code = code.replace(loop_content, modified_loop_content)
			with open(filepath, 'w') as new_file:
				new_file.write(code)