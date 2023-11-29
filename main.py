from utils import *
import os
from verifier import *

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
	for i in range(1):
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
	Trace: dict = {}
	for Dict in trace:
		for x in Dict:
			if x not in Trace:
				Trace[x] = [Dict[x]]
			else:
				Trace[x].append(Dict[x])

	# develop the heuristic to apply fix for the bug
	patches = generate_patch(Trace,variables)
	# print(patches)
	command = 'rm replica.cpp trace'
	# os.system(command)
	# run verifier on the fixed code 
	for i in range(1,(1<<len(patches))):
		patch_code = ''
		temp = []
		for j in range(0,31):
			if (i&(1<<j)):
				temp.append(patches[j])
		for j in range(len(temp)):
			patch_code+=temp[j]
			if j!=len(temp)-1:
				patch_code+= ' && '
		patch_code = f'if(!({patch_code}))break;'
		with open(filename,'r') as file:
			code = file.read()
		file.close()
		code = find_loop_pattern(code,patch_code)
		with open('replica.cpp','w') as temp_file:
			temp_file.write(code)
		temp_file.close()
		if(verifier('replica.cpp')):
			with open('output.cpp','w') as out:
				out.write(code)
			out.close()
			print("Passed")
			os.system('rm replica.cpp')
			break
	
	
	# if fixed return new code 