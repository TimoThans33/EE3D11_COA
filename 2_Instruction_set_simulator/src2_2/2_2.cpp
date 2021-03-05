#include <iostream>
#include <vector>
#include "registers.h"
#include "instruction.h"

/* vector to store instructions */
std::vector<Instruction*> *instructions;

int main(){
    Registers *reg = new Registers ();

    /* new instance of instruction vector */
    instructions =  new std::vector<Instruction*>;

    instructions->push_back (new OriInstruction(1, 0, 12));
    instructions->push_back (new OriInstruction(2, 0, 4));
    instructions->push_back (new OriInstruction(3, 0, 1));
    instructions->push_back (new AddInstruction(4, 4, 1));
    instructions->push_back (new SubInstruction(2, 2, 3));
    instructions->push_back (new BrneInstruction(2, 8, -3));

    /* dissassemble */
    std::vector<Instruction*>::iterator it;
    for (it = instructions->begin (); it < instructions->end (); it++)
    {
        (*it)->disassemble();
    }

    /* execute program */
    it = instructions->begin ();
    while (it >= instructions->begin () && it < instructions->end())
    {
        reg->setPC ((*it)->execute (reg));
        it = instructions->begin () + reg->getPC ();
    }
    /* print registers */
    reg->print();

    return 0;
}   