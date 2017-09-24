/* K&R Exercise 2.2
 */
#include <stdio.h>

#define MAXLINE 1000

int getline(char [], int);

main()
{
    int len;
    char line[MAXLINE];

    while((len = getline(line,MAXLINE)) > 0)
        printf("%s",line);
    return 0;
}

/* alternate version of getline without using
 * '&&' and '||' operators
 */
int getline(char line[], int lim)
{
    int i,c;

    i = 0;
    while (i < lim-1)
    {
        if ((c = getchar()) == EOF)
        {
            line[i] = '\0';
            return i;
        }
        else if (c == '\n')
        {
            line[i++] = c;
            line[i] = '\0';
            return i;
        }
        else
            line[i++] = c;
    }
    line[i] = '\0';
    return i;
}
