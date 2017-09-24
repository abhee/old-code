/* K&R Exercise 1.8
 * Count blanks, tabs and newlines
 */
#include <stdio.h>

main()
{
    int c,nb,nt,nl;

    nb=nt=nl = 0;

    while((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++nb;
        else if (c == '\t')
            ++nt;
        else if (c == '\n')
            ++nl;
    }

    printf("There are %d spaces, %d tabs and %d newlines in the input\n"\
            ,nb,nt,nl);
    return 0;
}

