from clang import cindex
import sys,re


class AST:
	def __init__(self) -> None:
		self.flag = False
	
	def parse_ast(self,node,variables, depth=0):
		try:
			if node.kind == cindex.CursorKind.VAR_DECL \
				and depth==1 and self.flag==False:
				variables.append((node.type.spelling,node.spelling))
			elif node.kind == cindex.CursorKind.FUNCTION_DECL \
				and node.spelling == 'main':
				self.flag = True
			elif self.flag == True \
				and node.kind==cindex.CursorKind.VAR_DECL \
				and depth>1:
				variables.append((node.type.spelling,node.spelling))
			for child in node.get_children():
				self.parse_ast(child,variables, depth + 1)
		except:
			print("Variables collection failed")
		
	
	def get_variables(self,file_path):
		variables = []
		try:
			index = cindex.Index.create()
			translation_unit = index.parse(file_path)
			ast = translation_unit.cursor
			self.parse_ast(ast,variables)
			self.flag = False
			return variables
		except:
			print("Parsing of AST failed..")


if __name__ == "__main__":
	filepath: str = None
	if len(sys.argv) > 1:
		filepath = sys.argv[1]
	ast = AST()
	variables = ast.get_variables(filepath)
	print(variables)