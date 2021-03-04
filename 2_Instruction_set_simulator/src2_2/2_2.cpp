#include <iostream>
#include "registers.h"
#include "instruction.h"

int main(){
    Registers reg;

    printf("PC: %d\n", reg.getPC());
    reg.setPC(reg.getPC()+1);
    printf("PC: %d\n", reg.getPC());
    
}