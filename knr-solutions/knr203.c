/* K&R Exercise 2.3
 * write a function htoi which converts a string of 
 * hexadecimal digits into its equivalent integer value
 */
#include <stdio.h>
#include <ctype.h>

int htoi(char []);
int chrfind(char, char []);

main()
{
    printf ("%d\n",htoi("0x163f"));
    printf ("%d\n",htoi("-0x234F"));
    return 0;
}

/* htoi: convert character representation of 
 * hex number to its decimal equivalent
 */
int htoi(char s[])
{
    char digits[] = "0123456789abcdef";
    int i,sign,num;

    i = num = 0;
    sign = 1;

    /* skip white spaces if any */
    while(isspace(s[i]))
        i++;

    /* record sign */
    if (s[i] == '-' || s[i] == '+')
    {
        sign = s[i] == '-'? -1: 1;
        i++;
    }
    
    /* skip 0x or 0X prefix of hex number */
    if (s[i] == '0')
    {
        i++;
        if (s[i] == 'X' || s[i] == 'x')
            i++;
    }

    /* convert digits */
    for (; isalnum(s[i]); i++)
        num = 16 * num + chrfind(tolower(s[i]), digits);
    return num * sign;
}

/* chrfind: returns location of character c in string s 
 * returns -1 if s doesnot contain c
 */
int chrfind (char c, char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
        if (c == s[i])
            return i;
    return -1;
}
