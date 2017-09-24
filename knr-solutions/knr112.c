/* K&R Exercise 1.12
 * Prints its input one word per line
 */
#include <stdio.h>

/* inside a word */
#define IN 1
/* outside a word */
#define OUT 0

main()
{
    int c, state;

    state = OUT;
    while((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;
            putchar('\n');
        }
        else if (state == OUT)
            state = IN;

        if (state == IN)
            putchar(c);
    }
    return 0;
}
