#include <iostream>
#include "registers.h"

using namespace std;

Registers::Registers()
{
    for(int i=0; i<MAX_REGISTERS; i++)
    {
        regstr[i].regVal = 0;
    }
}

void Registers::setRegister(int mgNum, int value)
{

}

int Registers::getRegister(int regNum)
{

}

void setPC (int value)
{

}

int getPC ()
{

}

void print(

)