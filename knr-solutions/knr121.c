/* K&R Exercise 1.21
 * Replace strings of blanks by minimum number of tabs
 * and blanks to achieve the same spacing
 */
#include <stdio.h>

#define TABSIZE 8
#define MAXLEN 1000
#define SPACE ' '
#define TAB '\t'

int getline(char [], int);
void printTab(char []);

main()
{
    int len;
    char line[MAXLEN];

    while ((len = getline(line, MAXLEN)) > 0)
    {
        printf("%s",line);
        printTab(line);
    }
    return 0;
}

/* getline : reads an input line converting strings of
 * blanks  by the minimum number of tabs and blanks
 * to achieve the same spacing.
 */
int getline(char line[], int lim)
{
    int c, i, col, totalBlanks, spacestoTab, blanks, tabs;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; )
    {
        if (c == SPACE)
        {
            /* first blank */
            totalBlanks = 1;

            while ((c = getchar()) == SPACE)
                ++totalBlanks;

            /* if previous character in the line is a tab */
            if(line[i-1] == TAB)
            {
                col = TABSIZE - (i-1) % TABSIZE;
                spacestoTab = TABSIZE - (i-1+col) % TABSIZE;
            }
            else
                spacestoTab = TABSIZE - i % TABSIZE;

            if (totalBlanks < spacestoTab)
                while(totalBlanks-- > 0)
                    line[i++] = SPACE;
            else
            {
                /* calculate minimum number of tabs required */
                tabs = (totalBlanks - spacestoTab) / TABSIZE + 1;
                /* calculate minimum number of blanks required */
                blanks = (totalBlanks - spacestoTab) % TABSIZE;

                while (tabs-- > 0)
                    line[i++] = TAB;
                while (blanks-- > 0)
                    line[i++] = SPACE;
            }
            line[i++] = c;
        }
        else
            line[i++] = c;
    }

    if(c == '\n')
        line[i++] = c;

    line[i] = '\0';
    return i;
}

/* printTab: makes tabs and spaces visible in the output 
 * in an unabiguous way. It shows tabs as \t and spaces
 * as +
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
