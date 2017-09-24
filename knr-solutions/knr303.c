/* K&R Exercise 3.3
 * expand (s1,s2)
 * expand pattern in s1 to complete list in s2
 * pattern can be "a-h0-5"
 * leading and trailing '-' are taken literally
 */
#include <stdio.h>

#define MAX 500

void expand(char [], char []);

main()
{
    char s1[] = "  -a-sA-P3-84-T";
    char s2[MAX];

    expand(s1, s2);
    puts(s1);
    puts(s2);
}

/* expand: expands pattern in s1 into s1 */
void expand(char pat[], char str[])
{
    int i,j,k,in_range;
    int start,end;
    
    i = in_range = 0;

    /* skip leading white spaces and '-' if any */
    while (!isalnum(pat[i]))
        i++;

    /* scan pattern  and determine start and end of each range */
    for( ; pat[i] != '\0'; i++)
    {
        if (isalnum(pat[i]))
        {
            if (!in_range)
            {
                if (pat[i+1] == '-')
                {
                    start = end = pat[i];
                    in_range = 1;
                }
            }
            else if (in_range)
            {
                if (isalnum(pat[i+1]) || pat[i+1] == '\0')
                {
                    end = pat[i];
                    in_range = 0;
                }
                else if (pat[i+1] == '-')
                    end = pat[i];
            }
        }
        else if (pat[i] == '-' && pat[i+1] == '\0')
            in_range = 0;

        /* expand the range in str */ 
        if (!in_range)
        {
            if (isupper(start) && isupper(end) || islower(start) && \
                    islower(end) || isdigit(start) && isdigit(end))
            {
                for (j = start; j <= end; j++)
                    str[k++] = j;
                str[k] = '\0';
            }
        }
    }
}

