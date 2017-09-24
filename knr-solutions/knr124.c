/* K&R exercise 1.24 
 * Rudimentary syntax checking for C programs 
 */
#include <stdio.h>

/* Maximum size of input line */
#define MAXLEN 1000
/* inside a comemnt or quote */
#define IN   1
/* outside of a comment or quote */
#define OUT  0

int getline(char [], int);

main()
{
    char line[MAXLEN];
    int len, i;
    /* a pair of parenthesises, brackets, braces
     * if other than zero it means they are not 
     * balanced i.e number of open parenthesises
     * brackets, braces is not equal to closed ones
     */
    int parens, brackets, braces;
    /* 1 if inside of a comment otherwise 0 */
    int in_comment;
    /* 1 if inside a string otherwise 0 */
    int in_string;
    /* 1 if inside a single quote otherwise 0 */
    int in_quote;
   
    parens = brackets = braces = 0;
    in_comment = in_string = in_quote = OUT;

    while ((len = getline(line, MAXLEN)) > 0)
    {
        i = 0;
        while (line[i])
        {
            if (line[i] == '[' || line[i] == '(' || line[i] == '{')
            {
                if(!in_comment && !in_string && !in_quote)
                    if (line[i] == '[')
                        ++brackets;
                    else if (line[i] == '(')
                        ++parens;
                    else if (line[i] == '{')
                        ++braces;
            }
            else if (line[i] == ']' || line[i] == ')' || line[i] == '}')
            {
                if(!in_comment && !in_string && !in_quote)
                    if (line[i] == ']')
                        --brackets;
                    else if (line[i] == ')')
                        --parens;
                    else if (line[i] == '}')
                        --braces;
            }
            else if (line[i] == '"')
            {
                if(!in_comment && !in_quote)
                    if(!in_string)
                        in_string = IN;
                    else if(in_string)
                        in_string = OUT;
            }
            else if (line[i] == '\'')
            {
                if(!in_comment && !in_string)
                    if(!in_quote)
                        in_quote = IN;
                    else if(in_quote)
                        in_quote = OUT;
            }
            else if (line[i] == '/')
            {
                /* maybe start of comment block */
                if(!in_string && !in_quote && !in_comment)
                    if(line[i+1] == '*')
                    {
                        in_comment = IN;
                        i++;
                    }
            }
            else if (line[i] == '*')
            {
                /* maybe end of comment block */
                if(!in_string && !in_quote && in_comment)
                    if (line[i+1] == '/')
                    {
                        in_comment = OUT;
                        i++;
                    }
            }
            i++;
        }
    }
    if (parens)
        printf("unbalanced parenthesise\n");
    if (brackets)
        printf("unbalanced bracket\n");
    if (braces)
        printf("unbalanced brace\n");
    if (in_comment)
        printf("unbalanced comment\n");
    if (in_string)
        printf("unbalanced string\n");
    if (in_quote)
        printf("unbalanced quote\n");
    
    if(!in_string && !in_comment && !in_quote && !parens \
            && !braces && !brackets)
        printf("Syntax appears to be correct\n");
    
    return 0;
}

/* Reads an input line */
int getline(char line[], int lim)
{
    int c, len, i;

    i = len = 0;

    while(i < lim-1 && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;
    
    if(c == '\n')
        line[i++] = c;
    
    line[i] = '\0';

    return i;
}
