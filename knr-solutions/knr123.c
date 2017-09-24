/* K&R Exercise 1.23
 * Remove all comments from C program
 */
#include <stdio.h>

#define MAXLINE 1000

int getline(char [], int);

main()
{
    char line[MAXLINE], newline[MAXLINE];
    int in_comment,in_string,in_quote;
    int i,j;

    in_comment = in_string = in_quote = 0;

    while ((len = getline(line, MAXLINE)) > 0)
    {
        for (i = 0, j = 0; line[i] != '\0'; ++i)
        {
            /* possibly start of the comment */
            if (line[i] == '/')
            {
                if (!in_comment && !in_string && !in_quote)
                    if (line[i+1] == '*')
                    {
                        in_comment = 1;
                        i++;
                    }
            }
            /* possibly end of the comment */
            else if (line[i] == '*')
            {
                if (in_comment && !in_string && !in_quote)
                    if (line[i+1] == '/')
                    {
                        in_comment = 0;
                        /* since in_comment becomes zero in this case
                         * the '/' is written to newline, so to avoid 
                         * this we've to increment i by 2, i.e to the
                         * character past '*' and '/'
                         */
                        i = i + 2;
                    }
            }
            /* is it a string */
            else if (line[i] == '"')
            {
                if (!in_quote && !in_comment)
                    if (!in_string)
                        in_string = 1;
                    else
                        in_string = 0;
            }
            /* is it a single quote? */
            else if (line[i] == '\'')
            {
                if (!in_string && !in_comment)
                    if (!in_quote)
                        in_quote = 1;
                    else
                        in_quote = 0;
            }

            /* copy each character of line to newline
             * which is not in comment
             */
            if(!in_comment)
            {
                newline[j] = line[i];
                j++;
            }
        }
        newline[j] = '\0';
        printf("%s",newline);
    }
    
    return 0;
}

/* getline: reads an input line */
int getline(char line[],int lim)
{
    int i,c;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n')
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';

    return i;
}
