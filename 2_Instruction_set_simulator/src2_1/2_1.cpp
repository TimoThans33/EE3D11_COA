#include <iostream>
#include "registers.h"

int main()
{
    Registers reg;

    /* checking getPC and setPC function */
    printf("PC: %d\n",reg.getPC());
    reg.setPC(reg.getPC()+1);
    printf("PC: %d\n", reg.getPC());
    /*checking setRegister and getRegister function */
    reg.setRegister(12, 8);
    printf("val ${%d} = %d \n", 12, reg.getRegister(12));
    /* checking register print function */
    reg.print();

    return 0;
}