# Performance Analyzer
## Prepartions
* Read http://www.cplusplus.com/doc/tutorial/
* Read the slides on C++
* Read the slides Computer Abstractions and Technology
* Read Chapter 1 and 1.6 performance

## Objectives
* Learn to use classes and objects
* Learn to use function overloading
* Learn about analyzing performance of different computer architectures

## Introduction
For analyzing the performance we need two compononents:
* The computer
* The program
We assume ISA to be dividided in:
* Arithmetic
* Store
* Load
* Branch

## Class Program
Objects of the class program provide an abstract representation of a program on the architecture of a specific computer. The instructions that make up the program are again divided into instruction classes.

## Results

Computer | Program | CPI | exe time |MIPS-global | MIPS-program
--- | --- | --- | --- |--- |--- |--- |--- |--- |--- |--- |---
0 | 0 | 2.08889 (I) | 6.42e-5 (s) | 363.636 (MIPS) | 478.723 (MIPS)
0 | 1 | 2.75 (I) | 0.0024024 (s) | 363.636 (MIPS) | 363.636 (MIPS)
0 | 2 | 2.85714 (I) | 0.0012018 (s) | 363.636 (MIPS) | 350 (MIPS)
1 | 0 | 2.15556 (I) | 0.00014898 (s) | 400 (MIPS) | 556.701 (MIPS)
1 | 1 | 3.15 (I) | 0.00576228 (s) | 400 (MIPS) | 380.952 (MIPS)
1 | 2 | 3.53571 (I) | 0.00288192 (s) | 400 (MIPS) | 339.394 (MIPS)
2 | 0 | 2.17778 (I) | 0.0001686 (s) | 571.429 (MIPS) | 918.367 (MIPS)
2 | 1 | 3.5 (I) | 0.0064068 (s) | 571.429 (MIPS) | 571.429 (MIPS)
2 | 2 | 3.71429 (I) | 0.0032044 (s) | 571.429 (MIPS) | 538.462 (MIPS)

## Answers to question
Compare the global MIPS rating to the program-dependent MIPS ratings. Comment on your findings.

--> We can clearly see big disrepencies between the program-dependent and global MIPS ratings. This corresponds to the findings in the lecture that there is not one best computer, but that it depends on multiple factors.

The book clarifies that the MIPS rating is not a good performance indicator. Does your simulation confirm this?

--> It is obvious that the highest MIPS rating does not correspond with the best execution time. It therefore confirms the statement that MIPS is not a good performance indicator.
