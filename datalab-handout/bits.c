/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    // first get ~^ then get ^
    return ~((~(~x & y)) & (~(x & ~y)));
}

/*
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
//the tmin is 10000...
    return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    // 0011111  010000
    //max = 01111111.... + 1 = 10000000 , complementary with max
    // but x = -1 also work, remove -1
    // add a & operation to remove -1
    return (!(~(x + 1) ^ x)) & !(!(x + 1));
}

/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    //  1 0  1  0 -> move one bit 0 1 0 1 what if we have something like 1 1 0 0  1 1 1 0
    //  1 0  1  0 & x -> 1 0  1  0
    // 1 0 1 0 =   1 0 1 0  1 0 1 0
    int x1 = 170;
    int x2 = 170 << 8;
    int x3 = 170 << 16;
    int x4 = 170 << 24;
    int oldBitsOne = x1 + x2 + x3 + x4;
    int compare = oldBitsOne & x;
    int minusCompare = ~compare + 1;
    return !(oldBitsOne + minusCompare);

}

/*
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    //thought: 0x30 = 00000000000000000000000000110000, 0x39 =00000000000000000000000000111001
    // start with 000000011 xxxxx  , shift  4 and then comare
    // right -> 4,  minus 11 =0

    //last four digit is from 0 0 0 0 - 1 0 0 1
    int minus3 = ~3 + 1;
    int shiftX = x >> 4;
    int difference = shiftX + minus3;
    int firstPremise = !difference;

    int lastFourDigitOfX = 15 & x;
    //last four digit >=0  and <= 9
    int minus10 = ~10 + 1;

    int difference2 = lastFourDigitOfX + minus10;
    int secondPremise = (difference2 >> 31) & 1;;

    return firstPremise & secondPremise;
}

/*
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    // if x = 1 isXTrue， xtrue = 1 then transfer to 11111  xfalse =0 transfer to 000 vice versa
    int isXTrue = ~((!(!x))) + 1;
    int isXFalse = (~(!x)) + 1;
    return (isXTrue & y) | (isXFalse & z);
}

/*
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */

int isLessOrEqual(int x, int y) {
    //use neg to realize -
    //  x-y<=0
    // -inf  inf  should be true
    // 1000000000   01111111 -> 10000001
    //corner case   011111   1000000
    //corner case   011111   0  -> res=
    //corner case   011111   100000
    // use four digits to see corner case

    int minusY = ~y + 1;
    int res = x + minusY;
    // res < 0 or

    int isXPositive = !(x >> 31);
    int isYNegative = (y >> 31) & 1;
    int isXPAndYN = isXPositive & isYNegative;
    return (((res >> 31) & 1) & !isXPAndYN) | (!res) | ((!isXPositive) & (!isYNegative));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    // if x is negative first digit is 1, if x is postive, turn to - x
    int minusX = ~x + 1;
    int logicNonNeg = (((x >> 31) & 1) | ((minusX >> 31) & 1));
    return ~logicNonNeg + 2;
}

/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    // for positive number, need to find the largest 1 and add 1
    // for negative number, need to find the largest 0 and add 1 (1 1 0 1 )  (1 0 1) are the same, because first
    // two left digits can counter, we can make all negative number to positive
    // for positive number, need to find the largest 1 and add 1
    // for negative number, need to find the largest 0 and add 1 (1 1 0 1 )  (1 0 1) are the same, because first
    // two left digits can counter, we can make all negative number to positive

    int abX, hasOneInLeft16, hasOneInLeft8, hasOneInLeft4, hasOneInLeft2, hasOneInLeft1;
    int sign = x >> 31;
    abX = (sign & ~x) | (~sign & x);

    //use binary search, compare first 16 digit.
    hasOneInLeft16 = !!(abX >> 16) << 4;  // 16 -> if there's one, 0 if there's no one
    // if all zero, search the right eight digit, else, search left digit
    abX = abX >> hasOneInLeft16;

    hasOneInLeft8 = !!(abX >> 8) << 3;
    abX = abX >> hasOneInLeft8;

    hasOneInLeft4 = !!(abX >> 4) << 2;
    abX = abX >> hasOneInLeft4;

    hasOneInLeft2 = !!(abX >> 2) << 1;
    abX = abX >> hasOneInLeft2;
    hasOneInLeft1 = !!(abX >> 1) << 0;
    abX = abX >> hasOneInLeft1;


    return hasOneInLeft16 + hasOneInLeft8 + hasOneInLeft4 + hasOneInLeft2 + hasOneInLeft1 + abX + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
    // first check if it is nan or inf, 255 is 1 1 1 1 1 1
    unsigned expDigits = (uf >> 23) & 255;
    unsigned sign = uf & -2147483648; // get the first digit

    if (expDigits == 255) {
        return uf;
    }

    //for denormorlized number, just left shift one digit
    if (expDigits == 0) {
        return ((~(1 << 31)) & (uf << 1)) | sign;
    }

    if (expDigits == 254) { // number*2 will overflow, just return infinity
        return (255 << 23) | sign;
    }

    return uf + (1 << 23); // for others just add 1
}

/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    int expDigits = (uf >> 23) & 255;
    unsigned inputFrac = uf & (~(511 << 23));
    int exp = expDigits - 127;
    unsigned reservedBit = (inputFrac >> (22 - exp)) << (22 - exp);
    int result;

    if (expDigits == 255) {
        -2147483648;
    }

    if (exp < 0) {
        return 0;
    }
    //add first one

    if (exp >= 31){
        return -2147483648;
    }

    inputFrac = inputFrac | (1 << 23);
    result = inputFrac >> (23 - exp);
    if( uf >= (1<<31) ){
        return -result;
    }
    return result;

}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */

unsigned floatPower2(int x) {
    unsigned bit = 23;
    if (x < -329) { // too small
        return 0;
    }

    if (x > 127) { // too large
        return 255 << bit;
    }

    if (x <= -127) { //dnorm
        return (1 << 24) >> (x - 126);
    }
    return (x + 127) << 23;  //norm


}
