# VHDL MIPS Assignments

## VHDL MIPS Assignment 2, Variant 1: sra and jal

In this variant of the assignment, you have to implement the following instructions:
* sra: shift right arithmetic
10100111 -> 11010011
* jal: jump and link
store the address of the next instruction in the return address register. This allows a subroutine to return to the main body routine after completion.
```
jal MySub
```
```
jr $ra
```

## VHDL MIPS Assignment 2, Variant 3: slt and bgezal.

In this variant of the assignment, you have to implement the following instructions:
* slt: set on less than
```
slt rd, rs, rt
```
rd <-- (rs<|rt)
Compare the contents of GPR rs and GPR rt as signed integers; record the Boolean result of the comparison in GPR rd. If GPR rs is less than GPR rt, the result is 1 (true); otherwise, it is 0 (fals).
GPR = general purpose register.

### operation
```
if GPR[rs]<GPR[rt] then
    GPR[rd]<-- 0^GPRLEN-1 || 1
else
    GPR[rd]<--0^GPRLEN
endif
```
| opcode | rs | rt | rd | shamt | funct |
| ------ | -- | -- | -- | ----- | ----- |
| 000000 | 10011 | 10110 | 10001 | 00000 | 101010 |

* bgezal: Branch on Greater Than or Equal to Zero and Link.
```
BGEZAL rs, offset
```
| REGIMM | rs | BGEZAL | offset |
| ------ | -- | ------ | ------ |
| 6 | 5 | 5 | 16 |
if GPR[rs] >= 0 then procedure_call

Place the return address link in GPR 31. The return link is the address of the second instruction following the branch, where execution continues after a procedure call.

An 18-big signed offset (the 16-bit offset field shifted left 2 bits) is added to the address of the instruction following the branch (not the branch itself), in the branch delay slot, to form a PC-relative effective target address.

If the contents of GPR rs are greater than or equal to zero (sign bit is 0), branch to the effective target address after the instruction in the delay slot is executed.