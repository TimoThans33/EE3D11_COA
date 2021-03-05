#include "program.h"

Program::Program(int x, int y, int z, int a) {
    numArith = x;
    numStore = y;
    numLoad = z;
    numBranch = a;
    numTotal = x + y + z + a;
    printStats();
}

Program::Program(int x, double y, double z, double a) {
    numTotal = x;
    numArith = y * numTotal;
    numStore = z * numTotal;
    numLoad = a * numTotal;
    numBranch = numTotal - numArith - numStore - numLoad;
    printStats();
}

void Program::printStats(void) {
    std::cout<<"Arithmic Instructions : "<<numArith<<" (I)"<<std::endl;
    std::cout<<"Store Instructions : "<<numStore<<" (I)"<<std::endl;
    std::cout<<"Load Instructions : "<<numLoad<<" (I)"<<std::endl;
    std::cout<<"Branch Instructions : "<<numBranch<<" (I)"<<std::endl;
    std::cout<<"--------------------------------------"<<std::endl;
    std::cout<<"Total : "<<numTotal<<std::endl;
    std::cout<<"--------------------------------------"<<std::endl;
}