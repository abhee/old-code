/* K&R Exercise 2.5
 * any(s1,s2) - returns first location in string s1
 * where any character from string s2 begins.
 */
#include <stdio.h>

int any(char [], char []);

main()
{
    char str1[] = "Hello world from abhijit";

    printf("%d\n",any(str1, "wafjfzy"));
    return 0;
}

/* any: returns first location in string s1 where any
 * character from string s2 occurs.
 */
int any(char s1[], char s2[])
{
    int i,j;

    for(i = 0; s2[i] != '\0'; i++)
        for(j = 0; s1[j] != '\0'; j++)
            if (s2[j] == s1[i])
                return i;
    return -1;
}
