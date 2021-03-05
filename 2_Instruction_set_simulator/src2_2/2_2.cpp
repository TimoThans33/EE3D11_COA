#include <iostream>
#include "registers.h"
#include "instruction.h"


int main(){
    int PC;
    Registers reg;

    Instruction instruction;
    AddInstruction add;
    SubInstruction sub;
    OriInstruction ori;
    BrnInstruction brne;

    /* make our little program */
    Instruction * ins1 = &add;
    ins1->set_values (8, 3, 6);
    Instruction * ins2 = &sub;
    ins2->set_values (16, 18, 22);
    Instruction * ins3 = &ori;
    ins3->set_values (24, 28, 30);
    Instruction * ins4 = &brne;
    ins4->set_values (12, 14, -4);

    /* dissassemble */
    ins1->disassemble();
    ins2->disassemble();
    ins3->disassemble();
    ins4->disassemble();

    /* set some arbitrary values in the registers */
    reg.setRegister(6, 4);
    reg.setRegister(22, 8);
    reg.setRegister(28, 5);
    reg.setRegister(30, 13);
    reg.setRegister(12, 11);

    PC = ins1->execute(&reg);
    reg.setPC(PC);
    printf("PC : %d\n", reg.getPC());
    PC = ins2->execute(&reg);
    reg.setPC(PC);
    printf("PC : %d\n", reg.getPC());
    PC = ins3->execute(&reg);
    reg.setPC(PC);
    printf("PC : %d\n", reg.getPC());
    PC = ins4->execute(&reg);
    reg.setPC(PC);
    printf("PC : %d\n", reg.getPC());
    reg.print();

    return 0;
}   