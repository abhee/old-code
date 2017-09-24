/* K&R Exercise 3.6
 * itoa with 3 arguments instead of 2.
 * 3rd argument is minimum field width. The converted
 * number must be padded with blanks on the left to 
 * make it wide enough
 */
#include <stdio.h>

#define MAX 256

void itoa(int, char [], int);
void reverse (char []);
int len (char []);

main()
{
    char str[MAX];

    itoa(68906787,str,8);
    puts(str);
    itoa(297,str,8);
    puts(str);
    itoa(54,str,8);
    puts(str);
    itoa(-8,str,8);
    puts(str);
    printf("%8d\n%8d\n%8d\n%8d\n",68906787,297,54,-8);
    return 0;
}

/* itoa : converts the number n to its equivalent character
 * representation in s padded to the left with blanks to
 * make it wide enough
 */
void itoa (int num, char s[], int width)
{
    int i, sign;

    /* record sign */
    if ((sign = num) < 0)
        num = -num; /* make num positive */

    i = 0;
    /* generate digits in reverse order */
    do
    {
        s[i++] = num % 10 + '0'; /* get next digit */
        num /= 10; /* delete it */
    }
    while (num > 0);

    /* insert minus symbol if number is negative */
    if (sign < 0)
        s[i++] = '-';
    
    /* pad the number with blanks to make it wide if necessary */
    if (i < width)
    {
        int blanks;
        blanks = width - i;
        while (blanks-- > 0)
            s[i++] = ' ';
    }
    s[i] = '\0';
    reverse (s);
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
