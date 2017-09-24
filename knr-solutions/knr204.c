/* K&R Exercise 2.4
 * delete each character in string s1 that matches
 * any character in string s2
 */
#include <stdio.h>

void squeeze(char [], char []);

main()
{
    char s[] = "hello world";
    puts(s);
    squeeze(s,"odr");
    puts(s);

    return 0;
}

/* squeeze: delete every character in s1 that matches any
 * character in s2
 */
void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (i = 0; s2[i] != '\0'; i++)
    {
        for (j = 0, k = 0; s1[j] != '\0'; j++)
            if (s1[j] != s2[i])
                s1[k++] = s1[j];
        s1[k] = '\0';
    }
}
