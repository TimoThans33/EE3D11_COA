#ifndef _REGISTERS_H_
#define _REGISTERS_H_

#define MAX_REGISTERS 32
class Registers
{
    private:
        int PC;
    public:
        Registers();
        void setRegister (int mgNum, int value);
        int getRegister( int regNum );
        void setPC (int value);
        int getPC ();
        void print();
    private:
        struct Rgstrs {
            int regVal;
        } regstr[MAX_REGISTERS];
};

#endif	/* _REGISTERS_H_ */