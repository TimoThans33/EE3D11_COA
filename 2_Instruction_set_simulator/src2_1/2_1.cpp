#include <iostream>
#include "registers.h"

int main()
{
    Registers *reg = new Registers ();

    /* checking getPC and setPC function */
    std::cout<<"\ntesting the getPC and setPC functions...\n";
    printf("PC: %d\n",reg->getPC());
    reg->setPC(reg->getPC()+1);
    printf("PC: %d\n", reg->getPC());

    /*checking setRegister and getRegister function */
    std::cout<<"\ntesting the setRegister and getRegister function...\n";
    reg->setRegister(12, 8);
    printf("register %d set to %d\n", 12, 8);
    printf("val ${%d} = %d \n", 12, reg->getRegister(12));
    
    /* checking register print function */
    reg->print();

    return 0;
}