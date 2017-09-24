/*K&R exercise 2.10
 * implementing function lower using conditional expression
 */
#include <stdio.h>

int lower(int);

main()
{
    char s[] = "HeLlo WOrlD!";
    int i;

    for (i = 0; s[i] != '\0'; i++)
        putchar(lower(s[i]));
    return 0;
}

int lower(int chr)
{
    return (chr >= 'A' && chr <= 'Z') ? (chr + 'a' - 'A') : chr;
}
