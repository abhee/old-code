/* K&R Exercise 4.14
 * A macro that interchanges two arguments of type t
 */
#include <stdio.h>

/* Swap two objects of type t */
#define SWAP(t, val1, val2) {t tmp; tmp = val1; val1 = val2; val2 = tmp;}

main()
{
    int a, b;
    char c, d;
    double p, q;
   
    a =12, b = 523;
    c = 'a', d = 'Z';
    p = 123.456, d = 1e-23;
    
    printf("a is %d\tb is %d\n",a,b);
    SWAP(int, a, b);
    printf("now a is %d\tb is %d\n",a,b);
    printf("c is %c\td is %c\n",c,d);
    SWAP(char, c, d);
    printf("now c is %c\td is %c\n",c,d);
    printf("p is %g\tq is %g\n",p,q);
    SWAP(float, p, q);
    printf("now p is %g\tq is %g\n",p,q);

    return 0;
}
