#ifndef COMPUTER
#define COMPUTER

#include "program.h"
#include <iostream>
/* class Computer provide an abstract representation of the computer. */
class Computer {
    public:
        // Clock rate in GHz
        double clockRateGHz;
        // CPI of instruction class Arith
        double cpiArith;
        // CPI of instruction class Store
        double cpiStore;
        // CPI of instruction class Load
        double cpiLoad;
        // CPI of instruction class Branch
        double cpiBranch;
        Computer(double, double, double, double, double);
        void printStats(void);
        double calculateGlobalCPI(Program p);
        double calculateExecutionTime(Program p);
        double calculateMIPS(Program p);
        double calculateMIPS(void);
};

#endif