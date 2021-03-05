#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#include <iostream>
#include "registers.h"

using namespace std;

/* Inheritance and polymorphism */

class Instruction {
    protected:
        int val1;
        int val2;
        int val3;
    public:
        void set_values(int a, int b, int c)
        {
            val1 = a; val2 = b; val3 = c;
        }
        void disassemble(){
            printf("add ${%d}, ${%d}, ${%d}\n", val1, val2, val3);
        }
        virtual int execute (Registers *){ return 0; };
        virtual ~Instruction()
        {
            std::cout<<"Destructing instruction \n";
        }
};

class AddInstruction : public Instruction
{
    public:
        int execute (Registers *r)
        {
            r->setRegister(val1, r->getRegister(val2)+r->getRegister(val3));
            return r->getPC()+1;
        }
        ~AddInstruction()
        {
            std::cout<<"Deconstructing AddInstruction\n";
        }
};


class SubInstruction : public Instruction
{
    public:
        int execute (Registers *r)
        {
            r->setRegister(val1, r->getRegister(val2) - r->getRegister(val3));
            return r->getPC()+1;
        }
        ~SubInstruction()
        {
            std::cout<<"Deconstructing SubInstruction\n";
        }
};
#endif /* _INSTRUCTION_H_ */
