/* K&R exercise 1.17
 * Prints lines which are longer than 80 characters
 */
#include <stdio.h>

/* Maximum allowed length of line */
#define MAXLEN 1000

int getline (char [], int);

main()
{
    char line[MAXLINE];
    int len;

    while ((len = getline(line, MAXLEN)) > 0)
        if (len > 80)
            printf("%s",line);
    return 0;
}

/* Reads a line of input */
int getline(char s[], int lim)
{
    int c,i;

    i = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';

    return i;
}
