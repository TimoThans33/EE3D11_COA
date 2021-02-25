#ifndef _REGISTERS_H_
#define _REGISTERS_H_

class Registers
{
    public:
        void setRegister (int mgNum, int value);
        int getRegister( int regNum );
        void setPC (int value);
        int getPC ();
        void print();
};

#endif	/* _REGISTERS_H_ */