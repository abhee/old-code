/* K&R Exercise 1.10
 * Relpaces tabs  by \t
 * Replaces each newline  by \n
 * Replaces backspace by \b
 */
#include <stdio.h>

main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\n')
        {
            putchar('\\');
            putchar('n');
        }
        else if (c == '\b')
        {
            putchar('\\');
            putchar('b');
        }
        else
            putchar(c);
    }
    putchar('\n');
    return 0;
}
