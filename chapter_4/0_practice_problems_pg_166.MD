Chapter 4 - The Building Blocks: Binary Numbers, Boolean Logic, and Gates
Practice problems pg. 166 

1. What is the value of the 8-bit binary quantity 10101000 if it is interpreted 
    (a) as an unsigned integer, and (b) as a signed integer represented in sign/magnitude notation?

    Solution:
    (a) 168
    (b) -40

2. What does the unsigned decimal value 99 look like in binary using 8 bits?

    Solution: 99 (decimal) = 01100011 (8-bit binary)

3. What do the signed integers -300 and +254 look like in binary using 10 bits and sign/magnitude
    integer representation? 

    Solution: 
    -300
    sign bit = 1(negative), magnitude 1001 0110 0
    Final 10-bit result: 1 100 1011 00

    +254 
    sign bit = 0(positive), magnitude 0111 1111 0 (make it 9-bit magnitude)
    Final 10-bit result: 0011 1111 10 

4. What is the value of the 8-bit binary quantity 1001 0111 when it is interpreted as 
    a sign/magnitude integer?

    Solution:
    1 001 0111
    from right to left 
    1 x 2^0 = 1
    1 x 2^1 = 2
    1 x 2^2 = 4
    0 x 2^3 = 0

    1 x 2^4 = 16
    0 x 2^5 = 0 (32)
    0 x 2^6 = 0 (64)

    last bit is negative
    ----------------- +
    total = -23

5. Using 4 bits and two's complement representation, what is the binary representation
    of the following signed decimal values:
    a. +6 
        Solution: 0110


    b. -3
        Solution: 1101

        -3 in 4-bit two's complement
        Steps:
            1. Start with +3
                3 -> 0011
            2. Invert bits
                0011 -> 1100
            3. Add 1
                1100 + 1 = 1101
                Result:
                    -3 -> 1101

6. Perform the following 5-bit binary addition showing the carry bit that propagates to each column. 
    Assume the numbers are unsigned binary quantities: 

    01110
   +01011

    Solution:

         01110 -> 14
        +01011 -> 11
        ------- +
         11001 -> 25

8. Using 10 bits to represent the mantissa (sign/magnitude) and 6 bits for the exponent (also sign/magnitude),
    show the internal representation of the following two values:
    
    a. +0.25
    b. -32 1/16

    Solution:
        Format given
        Mantissa: 10 bits -> sign/magnitude
        Exponent: 6 bits -> sign/magnitude

        Representation:
        [mantissa sign][mantissa magnitude][exponent sign][exponent magnitude]

        a. +0.25
            Solution:
                0.25 = 1/4 = 2 ^ -2 (which in binary is 0.01)

                Normalize, 
                We want form:

                1.xxxxx x 2 ^ e

                so:
                0.01 = 1.0 x 2 ^ -2 

                Mantissa (10 bits, sign/magnitude)
                Sign = 0 (positive)
                magnitude = 1.00000000 (fill to 9 bits after leading 1)
                
                Mantissa = 0 100000000

                Exponent (6 bits, sign/magnitude)
                Exponent = -2
                Sign = 1(negative)
                Magnitude = 00010
                Exponent = 1 00010

                Final answer:
                0 100000000 1 00010 

        b. -32 1 / 16
            Solution:
                1 / 16 = 2 ^ -4 (which in binary is 0.001)

                32 = 100000

                32 1 / 16 = 100000.0001 x 2 ^ 0
                          = 1.00000001 x 2 ^ 5

                Negative sign 1
                Mantissa = 1 100000001

                Exponent = +5
                Sign = 0 positive

                Exponent = 0 00101

                Final answer:
                1 100000001 0 00101

9. Explain exactly what happens when you add a 1 to the following 5-bit, two's complement value: 01111

    Solution:
        01111
        00001
        -----+
        10000 ?? -> become negative zero? 

        What does 10000 mean (in 5-bit two's complement)?
        MSB = 1 -> negative
        Find its value:

        Invert: 
            10000 -> 01111

        Add 1:
            01111 + 1 = 10000
        
        So it represents:
            -16

        The result is 10000, which represents -16 in two's complement.
        This occurs due to overflow, since +15 + 1 exceeds the maximum representable value.

10. Explain exaclty what happens when you perform addition on the following two sign/magnitude integer values:

    00111 (+7)
   +01110 (+14)

    Solution:
         00111 (+7)
        +01110 (+14)
        ------ +
         10001 -> become negative 1 

         The maximum of 5 bits is 2 ^ 5 which is 32 values, and we have to separate it 
         zero is 00000
         so there are 31 values more, which 1-15 and -1 - -16

         The result of adding +7 and +14 is +21, but this cannot be represented in 5-bit sign/magnitude format (maximum is +15). 
         Therefore, overflow occurs, and the result is invalid.

         Final takeaway
            - Do NOT treat sign/magnitude like normal binary addition
            - Always:
                1. Convert to decimal
                2. Add
                3. Check range
            - If out of range → overflow