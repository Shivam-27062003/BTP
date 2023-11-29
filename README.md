# BTP

This is the implementation of <b>automatic infinite loop detection and fix generator script</b> in Python, as the <b>B. Tech Project</b> under Prof. Kumar Madhukar (IIT Delhi). We have used CBMC checker for generating the trace, getting the pattern and hence developing a heuristic for fix.

# Getting Started

Installation Instructions

<b>USE Python version 3.8.0 or above</b>

`pip3 install -r requirement.txt`

The implementation is divided into following steps:

* Input of C++ file, replication for further operations
* Creation of <b>Abstract Syntax Tree</b> for tracking the global and local variable to main function
* Injection of artificial variables in the repicated file for the purpose of running CBMC checker
* Injection of <b>__CPROVER_assert()</b> statement and getting the trace using command `cbmc filename.cpp --unwind <number of unwinds> --trace`
* Extract the state of  the program using the trace and insert <b>__CPROVER_assume() </b> to make sure this state is not repeated in further extraction of trace
* Repeat the process k times
* Notice the pattern of state using k traces and design a heuristic for the fix
* Make a verifier that verifies whether a fix is correct or not
* Use backtracking on all possible changes that can be made to the program as suggested by k traces and the time verifier verifies it correct return the output
  
# Team Members

* Shivam Singh (2020CS10383)
* Sarthak (2020CS10379)
  
# Professor

* <b>Prof. Kumar Madhukar</b>

