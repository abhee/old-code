/* K&R exercise 1.18
 * Reverse input lines
 */
#include <stdio.h>

/* Maximum length of line allowed */
#define MAXLEN 1000

int getline(char [], int);
void reverse(char []);

main(void)
{
    int len;
    char line[MAXLEN];

    while((len = getline(line, MAXLEN)) > 0)
    {
        reverse(line);
        printf("Reversed => %s",line);
    }
    return 0;
}

/* Reads a line of input */
int getline(char line[], int lim)
{
    int c,i;

    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    
    if (c == '\n')
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    
    return i;
}

/* Reverses a string in place */
void reverse(char str[])
{
    int i, j, tmp, len;

    /* first calculate length of str */
    for (i = 0, len = 0; str[i] != '\0'; i++)
        ++len;

    /* reverse str in place */
    for (i = 0, j = len-2; i < j; i++, j--)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}
