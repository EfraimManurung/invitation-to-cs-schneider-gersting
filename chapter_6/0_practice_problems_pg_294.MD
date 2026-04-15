Chapter 6 - An Introduction to System Software and Virtual Machines
Practice problems pg. 294

1. Assume that register R and memory cells 80 and 81 contain the following values:
    R: 20 
    memory cell 80: 43
    memory cell 81: 97

    Using the instruction set shown in Figure 6.5, determine what value ends up in 
    register R and memory cells 80 and 81 after each of the following instruction is 
    executed. Assume that each question begins with the values shown above. 

    a. LOAD 80 
        - Copies the content of memory cell 80 into register R
        - After: R = 43, M[80] = 43, M[81] = 97
    b. STORE 81 
        - Copies the content of register R into memory cell 81
        - After: R = 20, M[80] = 43, M[81] = 20
    c. COMPARE 80
        - Compares R with M[80]: 20 vs 43
        - Sets condition codes (20 < 43) but values don't change
            - if CON(80) > R: 20 then GT = 1 else 0 (which is GT = 1)
        - After: R = 20, M[80] = 43, M[81] = 97
    d. ADD 81
        - R + CON(X) -> R
        - R: 20 + CON(81): 97 -> R: 117
        - After: R=117, M[80] = 43, M[81] = 97
    e. IN 80
        - Read input and stores it in memory cell 80
        - After: R = 20, M[80] = (input value), M[81] = 97
    f. OUT 81
        - Output, in decimal notation, the value stored in memory cell X.
        - Outputs the value from memory cell 81 to the console
        - After: Output display = 97

2. Assume that memory cell 50 contains a 4 and label L is equivalent to memory 
    location 50. What value does each of the following LOAD instructions load into
    register R?

    a. LOAD 50
        - Copies the content of memory cell 50 into register R
        - After: R = 4
        - LOAD 50 -> R = CON(50) = 4
    b. LOAD 4
        - Copies the content of memory cell 4 into register R
        - After: R = CON(4)
        - Note: Can't be specific number unless memory cell 4 is given

    c. LOAD L
        - Meaning CON(L) -> R, which is CON(L) -> 4 

    d. LOAD L+1 (Assume that this is legal.)
        - With L+1 = 51 then R = CON(51) = unknown unless memory cell 51 is given.

3. Explain why both the HALT operation code described in Figure 6.5 and the .END
    pseudo-op mentioned at the end of this section are needed in an assembly language
    program and what might happen if one or both were omitted. 
    
    Answer:
    HALT stops the CPU at runtime, while .END stops the assembler at assembly time 
    (and often helps define the program's boundary/start), so leaving either out can make execution run into garbage or make assembly produce the wrong program. 

4. Explain exactly what would occur if a processor tried to execute the following
    pair of instructions:
        LOAD  L
    L:  .DATA 1

    Answer:
     In short, LOAD L loads the data value 1 into R, and then execution "falls into" the data word and the CPU tries to execute it as code, leading to undefined or erroneous behavior. 
    
5. Assume machine language instructions occupy 16 bits, with the first four bits holding the op code (as given in Figure 6.5) and the final 12 bits holding the address of the operand. Also, assume that X corresponds to memory address 20 and Y corresponds to memory address 31. Show the internal binary representation of the following assembly language instructions:

With this information, we can write the full 16-bit instructions as:
- 16 bits = [opcode (4 bits)][address(12 bits)]

Given opcodes:
- LOAD = 0000
- SUBTRACT = 0101
- HALT = 1111

a. SUBTRACT X
    - Opcode: 0101
    - Address(X=20): 000000010100
    - Full 16-bit: 0101 000000010100
    
b. LOAD Y
    - Opcode: 0000
    - Address(Y=31): 000000011111
    - Full 16-bit: 0000 000000011111

c. HALT
    - Opcode: 1111
    - Address field unused → all zeros: 000000000000
    - Full 16-bit: 1111 000000000000
