#ifndef _REGISTERS_H_
#define _REGISTERS_H_

#define MAX_REGISTERS 32 //given number of registers


class Registers
{
    private:
        int PC;
    public:
        Registers(); //the constructor declaration
                    //a variable of the type 'Registers' can only be accessed by the following member functions
        void setRegister (int mgNum, int value);
        int getRegister(int regNum);
        void setPC (int value);
        int getPC();
        void print();
        struct Rgstrs {
            int regVal;
        } regstr[MAX_REGISTERS]; //this creates an array type object of struct type Rgstrs; regstr[x].regVal
                                //previous line can be replaced with Rgstrs regstr[MAX_REGISTERS]; so type_name object_name[object array size]
};

#endif	/* _REGISTERS_H_ */
