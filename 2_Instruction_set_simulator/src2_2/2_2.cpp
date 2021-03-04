#include <iostream>
#include "registers.h"
#include "instruction.h"


int main(){
    int PC;
    Registers reg;

    Instruction instruction;
    AddInstruction add;
    SubInstruction sub;
    Instruction * ins1 = &add;
    Instruction * ins2 = &sub;
    
    ins1->set_values (8, 3, 6);
    ins2->set_values (16, 18, 22);

    ins1->disassemble();
    ins2->disassemble();

    reg.setRegister(6, 4);
    reg.setRegister(22, 8);
    
    PC = ins1->execute(&reg);
    reg.setPC(PC);

    PC = ins2->execute(&reg);
    reg.setPC(reg.getPC()+1);
    reg.print();

    return 0;
}   