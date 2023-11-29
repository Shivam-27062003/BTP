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
