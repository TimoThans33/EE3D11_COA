#include "computer.h"
#include "program.h"

#define NUMBER_OF_PROGRAMS 3
#define NUMBER_OF_COMPUTERS 3

int main(int argc, char* argv[]){
    std::cout<<"Welcome to the performance analyzer"<<std::endl;
    std::cout<<"--------------------------------------"<<std::endl;
    // creating the programs
    Program* program = (Program*)malloc(sizeof(Program)*NUMBER_OF_PROGRAMS);
    Computer* arch = (Computer*)malloc(sizeof(Program)*NUMBER_OF_COMPUTERS);
    
    program[0] = Program(2000, 100, 100, 50);
    program[1] = Program(2000, 0.1, 0.4, 0.25);
    program[2] = Program(500, 100, 2000, 200);
    // creating the computer designs
    arch[0] = Computer(1, 2, 2, 3, 4);
    arch[1] = Computer(1.2, 2, 3, 4, 3);
    arch[2] = Computer(2, 2, 2, 4, 6);

    // create the algorithm and print results
    std::cout<<"Computer : Program : CPI : Exe Time : MIPS global : MIPS program "<<std::endl;

    for (int i=0; i<NUMBER_OF_COMPUTERS; i++){
        for (int j=0; j<NUMBER_OF_PROGRAMS; j++){
            std::cout<<i<<" : "<<j;
            std::cout<<" : "<<arch[i].calculateGlobalCPI(program[j])<<" (I)";
            std::cout<<" : "<<arch[i].calculateExecutionTime(program[j])<<" (ms)";
            std::cout<<" : "<<arch[i].calculateMIPS()<<" (MIPS)";
            std::cout<<" : "<<arch[i].calculateMIPS(program[j])<<" (MIPS)"<<std::endl;
        }
    }
    std::cout<<"--------------------------------------"<<std::endl;
}

