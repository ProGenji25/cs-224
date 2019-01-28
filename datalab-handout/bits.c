/* 
 * CS:APP Data Lab 
 *
 * Group 16 
 * Jordan Hall hjordan6
 * Zach Young zyoung3
 * Jordan Golden golde3
 * Trevor Brown trevorsb
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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
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
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* Rating 1 -- 2 points each */
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
	/*We created a word with all the even bits in the first byte set to the value of 1
	 Using bit shifts and the | operator, we created a word with all even bits assigned
	as 1 and all odd assigned as 0. */
	int a = 0x55;
	int b = (a << 8) | a;
	int c = (b << 16) | b;
  	return c;
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
	/*we know the 1's complimet of is a word of all ones, which is equivalent to -1
	 So we flipped the bits with the ~ operator */
	return ~0;
}
/* 
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
int upperBits(int n) {
	/*Using the !! resulting in a 0 or a 1 value, checking for an input of 0.
	 Then using bitshifts, we created a word filled with all 1s or 0s. and then
	shifted left again to create the word with the specified number of 1s and 0s */
	int a = !(!n);
	a <<= 31;
	a >>= 31;
	a <<= (32 + (~n +1));
	return a;
}
/* Rating 2 -- 3 points each */
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
	/*We isolated the specified byte from it's lower counterpart, using a shift by
	 value n<<3 (n being the number of bytes, n*8 or n<<3 being the number of bits)
	We then shifted right 24 bits, leaving the specified byte in the least significant
	position. Then by the operator & we removed any extraneous values. */
	x >>= (n << 3);
	x <<=  24;
	x >>= 24;
	x = (x & 0xff);
	return x;
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
	/*The exclusive or will return a word of all 0s if x and y are equal, but a non-zero
	word if not equal. Returning !!a will produce a 0 if they are equal and a 1 if otherwise */
  	int a = (x ^ y);
	return !(!a);
}
/* Rating 3 -- 2 points each */
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	/*We created a string of 1s and a string of 0s stored in variables a and b. Then we compared 
	y and z to a and b respectively. Depending on the original value of x, we turn y or z into
	a string of all 0s. By returning the added values of y and z, the value of whichever is not
	equal to 0 will be returned.*/
	int a = !(!x);
	int b = !x;
	a <<= 31;
	a >>= 31;
	y = (a & y);
	b <<= 31;
	b >>= 31;
	z = (b & z);	
  	return (y + z);
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
	/*The signx and signy variables create strings of all one's or all 0's from the leading
	significant bit so we could tell if the numbers were positive or negative.  The diffsgn
	is our first check, and if it returns all 1's, we know there is a positive number and a 
	negative number.  Else, all 0's says the sign is the same for both numbers.  If the signs
	are different, it just calls if x is greater than y based on that.  If it is same signs for
	both, the value itself is compared.*/
	int signx = x >> 31;
	int signy = y >> 31;
	int diffsgn = signx ^ signy;
	int sgndiff = (y + 1 + (~x)) >> 31;
	return !!(((~diffsgn) & sgndiff) | (diffsgn & signy));
}
/* Rating 4 -- 1 point each */
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
	/*We first checked the sign by assigning int a the value of x shifted
	over 31 bits. If the value is negative, it flips the bits, if not
	the bits will stay the same. We add !(!a)) so if the value is negative
	it adds a one to satisfy two's compliment. But if the value is positive, 
	a zero is added to no effect.*/
	int a = x >> 31;
	x = (x ^ a);
	x += !(!a);
  	return x;
}
/* Float Rating 2 -- 3 points each */
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
	/*In order to change the sign of a float you only need to change the first bit, so we add
	to uf a word with the most significant bit set to one, and the rest set to zero which switches
	the first bit and leaves the rest the same.
	The first if statement checks to see if the isolated exponent has all its bits set to one.
	The second if statment isolates the mantisa and checks to see if it's bits are set to 
	anything other than all zeros. The purpose of these if statements is to see if the input is
	NaN*/
	unsigned int a = (0x1 << 31);
	unsigned int x = uf + a;
	unsigned int exp = ((uf << 1) >> 24);
	if (exp == 0xff)
	{
		if ((uf << 9) != 0x00)
		{
			return uf;
		}
	}
	return x;
}
/* Float Rating 4 -- 1 point each */
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
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
int float_f2i(unsigned uf) {
	/*We isolate the sign, exponent, and fraction fields.  The implied leading one is added 
	to the frac field since we are always dealing with normalized floats.  If exp is all ones,
	it's out of bounds.  Negative biased exponents give a value less than one, so we just return
	0.  Once bias is dealt with on exp, we shift mantissa in a way that prevents memory overflow.
	Since the fraction bits are cast to an unsigned value, it's like the floating point was shifted
	to the end already.  We set that as a starting point and shift left or right depending on if the
	exponent is less than or greater the max number of fraction bits.  If the sign bit is 1, we 
	negate the result.
	*/
  	unsigned mant = ((uf << 9) >> 9) | (0x1 << 23);
	unsigned exp = ((uf << 1) >> 24);
	unsigned sign = (uf >> 31);
	unsigned bias = 127;
	if (exp == 0xff)
	{
		return 0x80000000u;
	}
	if (exp < bias)
	{
		return 0x0;
	}
	exp -= bias;
	if (exp >= 31)
	{
		return 0x80000000u;
	}
	if (uf == 0)
	{
		return 0x0;
	}
	if(exp >= 23)
	{
		mant = mant << (exp - 23);
	}
	else
	{
		mant = mant >> (23 - exp);
	}
	if(sign)
	{
		return -mant;
	}
	return mant;
}
