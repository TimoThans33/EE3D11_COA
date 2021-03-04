#ifndef PROGRAM
#define PROGRAM

#include <iostream>

class Program {
    public:
        // Arithmetic and  logic calculations
        int numArith;
        // Store data into memory
        int numStore;
        // Load data from memory
        int numLoad;
        // Conditional and unconditional jumps
        int numBranch;
        // Total number of instructions
        int numTotal;
        Program(int, int, int, int);
        Program(int, double, double, double);
        void printStats();
};

#endif