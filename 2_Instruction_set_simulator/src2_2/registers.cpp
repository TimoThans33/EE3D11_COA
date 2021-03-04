#include <iostream>
#include "registers.h"

using namespace std;

Registers::Registers()
{
    for(int i=0; i<MAX_REGISTERS; i++)
    {
        regstr[i].regVal = 0;
    }
    print();
    setPC(0);
}

void Registers::setRegister (int regNum, int value)
{
    regstr[regnum] = value;
}

int Registers::getRegister (int regNum)
{
    return regstr[regnum];
}

void Registers::setPC (int value)
{
    PC = value;
}

int Registers::getPC ()
{
    return PC;
}
void Registers::print()
{
    printf("\nAvailable registers (%d)\n", MAX_REGISTERS);
    for(int i=0; i<MAX_REGISTERS; i++)
    {
        printf("%d | %d\n", i, regstr[i].regVal);
    }
    printf("\n-------------------------------------------\n");
}
