#include <stdio.h>
#include <stdbool.h>
# define CHAR_BIT 8
int main()
{
	//check if two integers have opposite sign
	int x=1, y=2;               // input values to compare signs
bool f = ((x ^ y) < 0); // true iff x and y have opposite signs
	printf("\nSign check between %d and %d : %d",x,y,f);

	//absolute value
	int v=-9;
	unsigned int r;
	int const mask = v >> (sizeof(int )*CHAR_BIT-1);
	r=(v+mask)^mask;
	r=(v^mask)-mask;
	printf("\nAbs value of %d is: %d",v,r);

	//min or max of two integers
	r=y ^ ((x ^ y) & -(x < y));
	printf("\nMin of %d and %d: %d",x,y,r);
	printf("\nMax of %d and %d: %d",x,y,x ^ ((x ^ y) & -(x < y)));

	r = y + ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1))); // min(x, y)
	printf("\nMin of %d and %d: %d",x,y,r);
	r = x - ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1))); // max(x, y)
	printf("\nMax of %d and %d: %d",x,y,x ^ ((x ^ y) & -(x < y)));
	
	//check if a number is a power of two
	unsigned int p=3;
	f=p && !(p&(p-1));
	printf("\nIs %d a power of 2: %d",p,f);
	int b=-3; // convert this from using 5 bits to a full int
	struct {signed int b:5;} s;
	r = s.b = b;
	printf("\nSign Extend from constant bit width: %d",r);

	// Check if a bit is set at a position 
	int n=7,position=2;
 int bit_set = (n & (1 << position)) != 0;
	printf("\nIs %d's MSB set?: %d",n,bit_set);
}
