#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#include <iostream>
#include "registers.h"

using namespace std;

/* Inheritance and polymorphism */

class Instruction {
    public:
        Instruction(Registers r)
        {
            r.print();
            std::cout<<"Constructing instruction \n";
        }
        virtual ~Instruct()
        {
            std::cout<<"Destructing instruction \n";
        }
}
class AddInstruction : public Instruction
{
    AddInstruction(int a, int b, int c)
    {
        r.setRegister(a, r.getRegister(b)+r.getRegister(c)));
    }
};


class SubInstruction : public Instruction
{
    SubInstruction( int a, int b, int c)
    {
        r.setRegister( a, r.getRegister(b), r.getRegister(c) );
    }
}
#endif /* _INSTRUCTION_H_ */
