from utils import *
import os

def add_code_chunk(filename,modified_code : str):
	ast = create_ast(filename)
	variables = []
	extract_variables(ast,variables,False)
	modified_code = insert_declarations(modified_code,variables)
	code_chunk = create_code_chunk_CPROVER_assert(variables)
	# print(code_chunk)
	modified_code = find_loop_pattern(modified_code,code_chunk)
	return modified_code

def run_cbmc(modified_code: str,no_of_unwind: int):
	filename = 'verification.cpp'
	with open(filename,'w') as file:
		file.write(modified_code)
	input_path = filename
	output_path = 'trace'
	cbmc_command = 'cbmc {} --unwind {} --trace > {}'.format(input_path,no_of_unwind,output_path)
	os.system(cbmc_command)

def verifier(filename) -> bool:
	with open(filename,'r') as file:
		modified_code = file.read()
	code = add_code_chunk(filename,modified_code)
	run_cbmc(code,5)
	trace_path = 'trace.txt'
	variables = trace_extraction(trace_path)
	command = 'rm trace verification.cpp'
	os.system(command)
	if len(variables)==0:
		return True
	return False

if __name__ == "__main__":
	filename: str = None
	if len(sys.argv)>1:
		filename  = sys.argv[1]
	with open(filename,'r') as file:
		code = file.read()
	verified = verifier(filename)
	print(verified)