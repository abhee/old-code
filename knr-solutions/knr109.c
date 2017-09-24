/* K&R Exercise 1.9
 * Copy input to output replacing strings
 * of blanks with a single blank
 */
#include <stdio.h>

#define SPACE ' '

main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            /* put a single space */
            putchar(c);
            while((c = getchar()) == ' ')
                ;
        }
        putchar(c);
    }
    return 0;
}
