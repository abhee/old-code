/********************************
 * Shuffle : Simple puzzle game  *
 * Author  : Abhijit Soman       *
 * Date    : 20 Aug 2004         *
 ********************************/

#include <curses.h>
#include <stdlib.h>
#include <time.h>

/* Window parameters */
#define WIN_WIDTH   22
#define WIN_HEIGHT   9
#define WIN_STARTX  30
#define WIN_STARTY   7

/* Swap two objects of type t */
#define SWAP(t, a, b) {t c; c = a; a = b; b = c;}

/* Maximum moves allowed */
#define MAXMOVES 300

WINDOW *xwin;

char alpha[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', ' '};

void shuffle (char puzzle []);
int  CheckWin (char puzzle []);
void curs_init(void);
void reset_term(void);
void Banner (void);
void Print(char array[], int);

/* Main */
main ()
{
    char puzzle[16];
    int moves = 0;
    int pos = 0;
    int newgame = 0;

    srandom (time (NULL));
    curs_init();
    Banner();

    while (1)
    {
        moves = 0;
        newgame = 0;

        shuffle(puzzle); 
        wclear(xwin);
        wattron (xwin, COLOR_PAIR(3));
        box (xwin, ACS_VLINE, ACS_HLINE);
        wattroff (xwin, COLOR_PAIR(3));
        Print (puzzle, moves);

        while (moves < MAXMOVES)
        {
            for (pos = 0; pos < 16; pos++)
            {
                if (puzzle[pos] == ' ')
                {
                    switch (wgetch (xwin))
                    {
                        case KEY_LEFT:
                            if (pos != 3 && pos != 7 && pos != 11 && pos != 15)
                            {
                                SWAP(char, puzzle[pos], puzzle[pos + 1])
                                    moves++;
                            }
                            break;
                        case KEY_RIGHT:
                            if (pos != 0 && pos != 4 && pos != 8 && pos != 12)
                            {
                                SWAP(char, puzzle[pos], puzzle[pos - 1]);
                                moves++;
                            }
                            break;
                        case KEY_UP:
                            if (pos != 12 && pos != 13 && pos != 14 && pos != 15)
                            {
                                SWAP(char, puzzle[pos], puzzle[pos + 4]);
                                moves++;
                            }
                            break;
                        case KEY_DOWN:
                            if (pos != 0 && pos != 1 && pos != 2 && pos != 3)
                            {
                                SWAP(char, puzzle[pos], puzzle[pos - 4]);
                                moves++;
                            }
                            break;
                        case 'n':
                            newgame = 1;
                            break;
                        case 'q':
                            reset_term();
                            exit(0);
                            break;
                    }
                    break;
                }
            }
            wattron (xwin, COLOR_PAIR(3));
            box (xwin, ACS_VLINE, ACS_HLINE);
            wattroff (xwin, COLOR_PAIR(3));
            Print (puzzle, moves);

            /* After every move check whether the puzzle is completed */
            if (CheckWin(puzzle))
            {
                wattron (xwin, COLOR_PAIR(5));
                Print(puzzle, moves);
                wattroff(xwin, COLOR_PAIR(5));

                if (wgetch(xwin) == 'q')
                {
                    reset_term();
                    exit(0);
                }
                break;
            }

            /* Start new game */
            if (newgame)
                break;
        }

        /* Game over */
        if (moves == MAXMOVES)
        {
            wclear (xwin);
            mvwaddstr(xwin, 1, 2, "*** Game  Over ***");
            mvwaddstr(xwin, 3, 2, "Press any key to");
            mvwaddstr(xwin, 4, 2, "start new game");
            mvwaddstr(xwin, 6, 2, "Press \'q\' to quit");

            if (wgetch(xwin) == 'q')
            {
                reset_term();
                exit (0);
            }
        }
    }
    return 0;
}

/* Generates a random puzzle */
void shuffle (char puzzle[16])
{
    int rec[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int i, pos;

    for (i = 0; i < 16; i++)
    {
        do
        {
            pos = random() % 16;
        }
        while(rec[pos] != 0)
            ;
        puzzle[i] = alpha[pos];
        rec[pos] = 1;
    }
}

/* Check for winning condition */
int CheckWin (char puzzle[16])
{
    int i;

    for (i = 0; i < 16; i++)
        if (puzzle[i] != alpha[i])
            return 0;
    return 1;
}  

/* Initialize curses system */
void curs_init()
{
    initscr ();
    cbreak();
    noecho();
    curs_set(0);
    xwin = newwin (WIN_HEIGHT, WIN_WIDTH, WIN_STARTY, WIN_STARTX);
    keypad (xwin, TRUE);
    start_color ();
    init_pair (1, COLOR_BLUE, COLOR_WHITE);
    init_pair (2, COLOR_GREEN, COLOR_BLACK);
    init_pair (3, COLOR_RED, COLOR_WHITE);
    init_pair (4, COLOR_BLACK, COLOR_WHITE); 
    init_pair (5, COLOR_YELLOW, COLOR_WHITE);
    wbkgd (xwin, COLOR_PAIR (1));
}

/* End curses session and restore the terminal
 * to its previous state */
void reset_term()
{
    echo ();
    nocbreak();
    curs_set (1);
    delwin (xwin);
    endwin ();
}

/* Display puzzle */
void Print (char puz[16], int no_of_moves)
{
    int i = 0, X = 2, Y = 1;

    for (i = 0; i < 16; i++)
    {
        mvwaddch (xwin, Y, X, puz[i]);
        if (i == 3 || i == 7 || i ==11)
        {
            X = 2;
            Y += 2;
        }
        else
            X += 3;
    }
    wattron (xwin, COLOR_PAIR(4));
    mvwaddstr (xwin, 3, 15, "Moves");
    mvwprintw (xwin, 4, 15, "%d", no_of_moves);
    wattroff (xwin, COLOR_PAIR(4));
}

/* Print banner */
void Banner ()
{
    attron(COLOR_PAIR(2));  
    mvaddstr (6, 25, "          W E L C O M E ");
    mvaddstr (7, 25, "               To");
    mvaddstr (8, 25, "      _            __  __ _");
    mvaddstr (9, 25, "     | |          / _|/ _| |");
    mvaddstr (10, 25, "  ___| |__  _   _| |_| |_| | ___");
    mvaddstr (11, 25, " / __| '_ \\| | | |  _|  _| |/ _ \\");
    mvaddstr (12, 25, " \\__ \\ | | | |_| | | | | | |  __/");
    mvaddstr (13, 25, " |___/_| |_|\\__,_|_| |_| |_|\\___|");
    mvaddstr (15, 25, "              By          ");
    mvaddstr (16, 25, "         ABHIJIT  SOMAN     ");
    attroff(COLOR_PAIR(2));
    getch ();
    clear ();
    refresh ();
}
