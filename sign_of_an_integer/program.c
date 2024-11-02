#include <stdio.h>
#define CHAR_BIT 8
int main()
{
	int v=-2;      // we want to find the sign of v
int sign1,sign2,sign3,sign4,sign5,sign6,sign7;   // the result goes here 

// CHAR_BIT is the number of bits per byte (normally 8).
sign1 = -(v < 0);  // if v < 0 then -1, else 0. 
	printf("Sign1: %d\n",sign1);
// or, to avoid branching on CPUs with flag registers (IA32):
sign2 = -(int)((unsigned int)((int)v) >> (sizeof(int) * CHAR_BIT - 1));
	printf("Sign2: %d\n",sign2);
// or, for one less instruction (but not portable):
sign3 = v >> (sizeof(int) * CHAR_BIT - 1);
	printf("Sign3: %d\n",sign3);

sign4 = +1 | (v >> (sizeof(int) * CHAR_BIT - 1));  // if v < 0 then -1, else +1
	printf("Sign4: %d\n",sign4);

	sign5 = (v != 0) | -(int)((unsigned int)((int)v) >> (sizeof(int) * CHAR_BIT - 1));
	printf("Sign5: %d\n",sign5);
// Or, for more speed but less portability:
sign6 = (v != 0) | (v >> (sizeof(int) * CHAR_BIT - 1));  // -1, 0, or +1
	printf("Sign6: %d\n",sign6);
// Or, for portability, brevity, and (perhaps) speed:
sign7 = (v > 0) - (v < 0); // -1, 0, or +1
	printf("Sign7: %d\n",sign7);
int sign8 = 1 ^ ((unsigned int)v >> (sizeof(int) * CHAR_BIT - 1)); // if v < 0 then 0, else 1
	printf("Sign8: %d\n",sign8);
}
