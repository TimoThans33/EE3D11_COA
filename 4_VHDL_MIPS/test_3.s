A:
    addi $1, $0, 5      # $1=5
    addi $2, $0, 10     # $2=10
    slt $3, $1, $2      # $3=1 ($1<$2)
    slt $4, $2, $1      # $4=0 ($2<!$1)
    j B                 # jump to B
B:
    bgezal $3, C        # $3>=0 so jump to C
    addi $5, $0, 1      # $5=1 skip this
C:
    addi $7, $0, -1     # $6=-1
    bgezal $7, D        # $6!>=0 so move to next instruction
    j Z
D:
    addi $6, $0, 1      # $6=1 skip this
Z:
    j Z                 # loop for simulation
