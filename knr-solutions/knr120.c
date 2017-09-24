/* K&R Exercise 1.20
 * Converts tabs in the input to spaces
 */
#include <stdio.h>
#include <string.h>

#define TABSIZE 8
#define SPACE ' '
#define MAXLEN 1000

int getline(char [], int);
void printTab(char []);

main()
{
    char line[MAXLEN];
    int len;

    while((len = getline(line, MAXLEN)) > 0)
    {
        printf("%sLength ==> %d\n", line, len);
        printTab(line);
    }
    return 0;
}

/* Specialized version of getline. It replaces tab
 * characters in the input with proper number of spaces
 */
int getline(char s[], int lim)
{
    int c, i, spaces;
    
    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; )
    {
        /* interpret tab as spaces */ 
        if (c == '\t')
        {
            spaces = TABSIZE - i % TABSIZE;
            /* spaces = ((i/TABSIZE) * TABSIZE) + TABSIZE - i;*/
            while (spaces-- > 0)
                s[i++] = SPACE;
        }
        else
            s[i++] = c;
    }
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* printTab: makes tabs and spaces visible in the output in 
 * an unabiguous way. It shows tabs as \t and spaces as +
 */
void printTab(char line[])
{
    int i;

    for (i = 0; line[i]; i++)
    {
        if (line[i] == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        else if (line[i] == SPACE)
            putchar('+');
        else 
            putchar(line[i]);
    }
}
