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
        virtual void disassemble(){ };
        virtual int execute (Registers *){ return 0; };
        virtual ~Instruction() {};
};

class AddInstruction : public Instruction
{
    public:
        int execute (Registers *r)
        {
            r->setRegister(val1, r->getRegister(val2)+r->getRegister(val3));
            return r->getPC()+1;
        }
        void disassemble(){
            printf("add ${%d}, ${%d}, ${%d}\n", val1, val2, val3);
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
        void disassemble(){
            printf("sub ${%d}, ${%d}, ${%d}\n", val1, val2, val3);
        }
        ~SubInstruction()
        {
            std::cout<<"Deconstructing SubInstruction\n";
        }
};

class OriInstruction : public Instruction
{
    public:
        int execute (Registers *r)
        {
            r->setRegister(val1, r->getRegister(val2) | r->getRegister(val3));
            return r->getPC()+1;   
        }
        void disassemble(){
            printf("ori ${%d}, ${%d}, %d\n", val1, val2, val3);
        }
        ~OriInstruction()
        {
            std::cout<<"Deconstructing OriInstruction\n";
        }
};

class BrnInstruction : public Instruction
{
    public:
        int execute (Registers *r)
        {
            if (r->getRegister(val1) != r->getRegister(val2))
            {
                return r->getPC()+1+val3;
            }
            else
            {
                return r->getPC()+1;
            }
        }
        void disassemble(){
            printf("brne ${%d}, ${%d}, %d\n", val1, val2, val3);
        }
        ~BrnInstruction()
        {
            std::cout<<"Deconstructing BrnInstruction\n";
        }
};
#endif /* _INSTRUCTION_H_ */
