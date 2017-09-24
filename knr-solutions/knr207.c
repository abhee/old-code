/* K&R Exercise 2.7
 * inverts n bits in x that begin at position p
 */
#include <stdio.h>

#define MAX 256

unsigned invert (unsigned, int, int);
void bits(unsigned);
void reverse(char []);
unsigned len(char []);

main()
{
    printf("%d\n",5692);
    bits(5692);
    bits(invert(5692,8,4));
    return 0;
}

/* invert: inverts n bits in x which begin at position p */
unsigned invert(unsigned x, int p, int n)
{
    return x ^ ~(~0 << n) << (p+1-n);
}

/* bits: show bit pattern of n */
void bits(unsigned n)
{
    int i;
    char s[MAX];

    i = 0;
    while (n > 0)
    {
        s[i++] = n % 2 + '0';
        n /= 2;
    }
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
