/* K&R Exercises 4.3 to 4.10
 * RPN Calculator
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define NAME '1'

void push(double);
double pop(void);
void top(void);
void swap(void);
void duplicate(void);
int getop(char []);
int getch(void);
void ungetch(int);
int Getch(void);
void unGetch(int);

main()
{
    int type;
    double op2;
    /* array for fetching operands and operators */
    char s[MAXOP];
    /* array for storing variables */
    int vars[26];

    while ((type = getop(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case NAME:
                if (!strcmp(s, "sin"))
                    push(sin(pop()));
                else if (!strcmp(s, "cos"))
                    push(cos(pop()));
                else if (!strcmp(s, "tan"))
                    push(tan(pop()));
                else if (!strcmp(s, "log"))
                    push(log10(pop()));
                else if (!strcmp(s, "ln"))
                    push(log(pop()));
                else if (!strcmp(s, "exp"))
                    push(exp(pop()));
                else if (!strcmp(s, "pow"))
                {
                    op2 = pop();
                    push(pow(pop(), op2));
                }
                else
                    printf("error: unknown function\n");
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                push(pop() / op2);
                break;
            case '%':
                op2 = pop();
                push(fmod(pop(), op2));
                break;
            case '^':
                top();
                break;
            case '@':
                duplicate();
                break;
            case '>':
                swap();
                break;
            case '\n':
                printf("\t%.8g\n",pop());
                break;
            default:
                printf("error: wrong command \n");
                break;
        }
    }
    return 0;
}

/* Stack manipulation functions */
#define MAXVAL 100

static int sp = 0; /* next free stack position */
static double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
        return 0.0;
}

/* Exercise 4.4 */
/* top: print top of the stack */
void top(void)
{
    printf("%.8g\n", val[sp-1]);
}

/* duplicate: duplicate topmost element of the stack */
void duplicate(void)
{
    val[sp] = val[sp-1];
    sp++;
}

/* swap: swap top two elements of the stack */
void swap(void)
{
    double tmp;

    tmp = val[sp-1];
    val[sp-1] = val[sp-2];
    val[sp-2] = tmp;
}

/* Exercise 4.3 and 4.5
 * Support for negative numbers
 * Support for library functions
 */

/* getop : reads next operator or operand from input */
int getop(char s[])
{
    int c, next, i = 0;
    char retval;

    while((s[i] = c = getch()) == ' ' || c == '\t')
        ;
    s[i+1] = '\0';

    if(!isalnum(c) && c != '.')
    {
        if ((c == '+' || c == '-'))
            if (isdigit(next = getch()) || next == '.')
                s[++i] = c = next;
            else
            {
                ungetch(next);
                return c;
            }
        else
            return c;
    }

    if (isalpha(c)) /* collect function names and/or variable names */
    {
        while(isalpha(s[++i] = c = getch()))
            ;
        retval = NAME;
    }
    else
    {
        if (isdigit(c)) /* collect integer part */
            while(isdigit(s[++i] = c = getch()))
                ;
        if (c == '.') /* collect fraction part */
            while(isdigit(s[++i] = c = getch()))
                ;
        retval = NUMBER;
    }
    s[i] = '\0';

    ungetch(c);
    return retval;
}

/* get/unget a character from/to input stream 
 * 
 * getch: reads a character from stdin or a pushed 
 * back character from input buffer
 *
 * ungetch: pushes a character on input
 *
 * ungets: pushes an entire input string on input
 */

/* Size of input buffer */
#define BUFSIZE 100

/* buffer too hold pushed back characters */
static int buf[BUFSIZE];
/* next free position in buffer */
static int bufp;

/* getch: return a (possibly) pushed back character */
int getch(void)
{
    return (bufp > 0)? buf[--bufp]:getchar();
}

/* ungetch: push a character back on input */
void ungetch(int ch)
{
    if (bufp < BUFSIZE)
        buf[bufp++] = ch;
    else
        printf("error: input buffer full");
}

/* Exercise 4.7
 * ungets: push an entire string back on input. 
 * It relies on ungetch to push back individual 
 * characters in the string, so it doesnot need 
 * to know anything about buf and bufp
 */
void ungets(char s[])
{
    int i = 0;

    while(s[i])
    {
        ungetch(s[i]);
        i++;
    }
}

/*****************************************************************/
/* Exercise 4.8 
 * These functions are similar to the above functions 
 * except that they assume that only a single character 
 * pushback is required.
 */

/* flag indicates if there is a pushed back character */
static int flag = 0;
static int ch;

/* getch: get a (possibly) pushed back character */
int Getch(void)
{
    if (flag)
    {
        flag = 0;
        return ch;
    }
    else
        return getchar();
}

/* ungetch: push a character c back into input */
void unGetch(int c)
{
    ch = c;
    flag = 1;
}
