/* K&R Exercise 1.18
 * Remove trailing blanks and remove blank lines entirely
 */
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline(char [], int);
void remblanks(char [], int);

main()
{
    int len;
    char line[MAXLINE];

    while((len = getline(line, MAXLINE)) > 0)
    {
        printf("Original length -> %d\n",len);
        printf("%s",line);
        remblanks(line, len);
        printf("New length -> %d\n",strlen(line));
        printf("%s",line);
    }
    return 0;
}

/* getline: Reads a line in s, return length */
int getline (char s[], int lim)
{
    int c,i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n';i++)
        s[i] = c;
    
    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

/* remblank: Removes trailing blanks and tabs from a string
 * it deletes entire blank strings
 */
void remblanks(char s[], int length)
{
    int i;

    for (i = length-2; i > 0 && (s[i] == ' ' || s[i] == '\t'); i--)
        ;
    if (i == 0)
        if (s[i] == ' ')
            s[i] = '\0';
        else
        {
            s[++i] = '\n';
            s[++i] = '\0';
        }
    else
    {
        s[++i] = '\n';
        s[++i] = '\0';
    }
}
