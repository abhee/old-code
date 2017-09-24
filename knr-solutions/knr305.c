/* K&R Exercise 3.5
 * itob(n,s,b) formats 'n' as base 'b' integer in 's'
 */
#include <stdio.h>

#define MAX 256

void itob (int, char [], int);
void reverse (char []);
int len (char []);

main()
{
    char str[MAX];
    int i;
    
    for(i = 2; i <= 36; i++)
    {
        itob(5678,str,i);
        printf("%d in base %d is %s\n",5678, i, str);
    }
    return 0;
}

/* itob: converts integer n into base b character 
 * representation in string s
 */
void itob(int n, char s[], int b)
{
    char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    int i, sign;

    /* base value must be between 2 and 36 inclusive */
    if (b < 2 || b > 36)
    {
        printf("error: value of base must be base >= 2 and base <= 36 \n");
        exit(-1);
    }
    
    /* record sign */
    if ((sign = n) < 0)
        n = -n; /* make n positive */

    i = 0;
    /*generate digits in reverse order */
    do 
    {
        /* get next digit */
        s[i++] = digits[n % b];
        /* delete it */
        n /= b;
    }
    while (n > 0);
    
    if (b == 8)
        s[i++] = '0';
    else if (b == 16)
    {
        s[i++] = 'x';
        s[i++] = '0';
    }

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
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
int len (char str[])
{
    int i;

    for(i = 0; str[i] != '\0'; i++)
        ;
    return i;
}
