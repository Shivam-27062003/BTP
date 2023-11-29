from utils import *
import os

if __name__ == "__main__":
	# take input c++ file and replicate the file 
	filename: str = None
	if len(sys.argv)>0:
		filename = sys.argv[1]
	with open(filename,'r') as file:
		code = file.read()
	with open('replica.cpp','w') as temp_file:
		temp_file.write(code)
	file.close()

	# inject the variables that need to injected for CPROVER_assert
	ast = create_ast('replica.cpp')
	variables = []
	extract_variables(ast,variables,False)
	with open('replica.cpp','r') as file:
		code = file.read()
	code = insert_declarations(code,variables)

	# inject the CPROVER_assert statement
	code_chunk = create_code_chunk_CPROVER_assert(variables)
	code = find_loop_pattern(code,code_chunk)
	file.close()
	with open('replica.cpp','w') as file:
		file.write(code)

	# cbmc check for the modified file using command 'cbmc filename.cpp --unwind 5 --trace > filename.txt'
	command = 'cbmc {}.cpp --unwind 5 --trace > {}'.format('replica','trace')
	os.system(command)

	# trace sample extraction
	trace = []
	trace.append(trace_extraction('trace'))

	# inject cbmc assume statement and again get the trace repeat it k times
	for i in range(30):
		with open('replica.cpp','r') as file:
			code = file.read()
			file.close()
		code = create_code_chunk_CPROVER_assume(code,variables,trace[i])
		if code != None:
			with open('replica.cpp','w') as file:
				file.write(code)
		command = 'cbmc {}.cpp --unwind 5 --trace > {}'.format('replica','trace')
		trace.append(trace_extraction('trace'))
		os.system(command)

	# with k sample of traces find the pattern of trace and failure
	for x in trace:
		print(x)

	# develop the heuristic to apply fix for the bug

	# run verifier on the fixed code 

	# if fixed return new code 

	command = 'rm replica.cpp trace'
	os.system(command)