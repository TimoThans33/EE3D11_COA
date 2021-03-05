#include "computer.h"

/* constructor */
Computer::Computer(double x, double y, double z, double a, double b) {
    clockRateGHz = x;
    cpiArith = y;
    cpiStore = z;
    cpiLoad = a;
    cpiBranch = b;
    printStats();
}

/* Prints the configuration of the computer */
void Computer::printStats(void){
    std::cout<<"Clock Rate : "<<clockRateGHz<<" (GHz)"<<std::endl;
    std::cout<<"Instruction Arith : "<<cpiArith<<" (CPI)"<<std::endl;
    std::cout<<"Instruction Store : "<<cpiStore<<" (CPI)"<<std::endl;
    std::cout<<"Instruction Load : "<<cpiLoad<< " (CPI)"<<std::endl;
    std::cout<<"Instruction Branch : "<<cpiBranch<<" (CPI)"<<std::endl;
    std::cout<<"--------------------------------------"<<std::endl;
}

/* return the value of the global cpi of the computer implementation */
double Computer::calculateGlobalCPI(Program p){
    return (p.numArith * cpiArith + p.numStore * cpiStore + p.numLoad * cpiLoad + p.numBranch * cpiBranch) / p.numTotal; 
}
/* return the execution time of the program */
double Computer::calculateExecutionTime(Program p) {
    return (p.numArith * cpiArith + p.numStore * cpiStore + p.numLoad * cpiLoad + p.numBranch * cpiBranch) / (clockRateGHz*1000000); 
}
/* return the mips rating of a program */
double Computer::calculateMIPS(Program p) {
    return 1000 * clockRateGHz * p.numTotal / (p.numArith * cpiArith + p.numStore * cpiStore + p.numLoad * cpiLoad + p.numBranch * cpiBranch);
}

double Computer::calculateMIPS(void) {
    return 1000 * clockRateGHz * 4 / (cpiArith + cpiStore + cpiLoad + cpiBranch);
}