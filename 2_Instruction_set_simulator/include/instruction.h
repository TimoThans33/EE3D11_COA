#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#include <iostream>
#include "registers.h"

using namespace std;

/* Inheritance and polymorphism */

class Instruction {
    public:
        Instruction()
        {
            std::cout<<"Constructing instruction \n";
        }
        virtual ~Instruct()
        {
            std::cout<<"Destructing instruction \n";
        }
}
class AddInstruction : public Instruction
{
    AddInstruction(Registers r, int a, int b, int c)
    {
        setRegister(a, r.getRegister(b)+r.getRegister(c)))
    }
};

class OriInstruction : public OriInstruction
{

};
#endif /* _INSTRUCTION_H_ */
