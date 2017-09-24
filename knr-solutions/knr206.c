/* K&R Exercise 2.6
 * setbits(x,p,n,y) - sets n bits starting from position p
 * to rightmost n bits of y
 */
#include <stdio.h>

#define MAX 256

unsigned setbits(unsigned , int , int , unsigned);
void bits(unsigned);
void reverse(char []);
unsigned len(char []);

main()
{
    printf("%d\n",5692);
    printf("%d\n",4567);
    bits(5692);
    bits(4567);
    printf("setbits(5692,8,3,4567)=>\n");
    bits(setbits(5692,8,3,4567));
    return 0;
}

/* setbits: sets nbits in x which begins at position p
 * to rightmost n bits of y.
 *
 * It uses property of '^' operator
 * if x ^ y = z then if either x or y is known, we can 
 * get other operand by XORing it with z.
 *
 * e.g. setbits(x,p,n,y)
 * 1. n bits in x which begin at position p are read
 *    by (x >> (p+1-n)) & ~(~0 << n)
 * 2. rightmost n bits of y are read by (y & ~(~0 << n))
 * 3. Now a bitmask is prepared by conencting steps 1 and 2
 *    by XOR and the result is left shifted by (p+1-n).
 * 4. Now (x & bitmask) sets n bits in x which begins
 *    at position p to that of rightmost n bits of y.
 */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return x ^ ((x >> (p+1-n)) & ~(~0 << n) ^ (y & ~(~0 << n)) << (p+1-n));
}

/* bits: show bit pattern of n */
void bits(unsigned n)
{
    int i;
    char s[MAX];

    i = 0;
    do
    {
        s[i++] = n % 2 + '0';
        n /= 2;
    }
    while (n > 0);
    
    s[i] = '\0';
    reverse(s);
    printf("%s\n",s);
}

/* reverse: reverses string in place */
void reverse(char s[])
{
    int i,j;
    char tmp;

    for(i = 0, j = len(s)-1; i < j; i++, j--)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

/* len: return length of string */
unsigned len (char str[])
{
    int i;

    for(i = 0; str[i] != '\0'; i++)
        ;
    return i;
}
