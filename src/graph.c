
#include "expression_process.h"
#include <stdio.h>

#define X 80
#define Y 25

void fill_screen(char screen[X][Y], struct vector expression);
void print_screen(char screen[X][Y]);

int main()
{
    char expr_string[400];
    char screen[X][Y];

    scanf("%s", expr_string);

    struct vector expr = expression_to_postfix(expr_string);

    if (vector_is_valid(expr))
    {
        fill_screen(screen, expr);
        print_screen(screen);
        vector_destroy(&expr);
    } else
    {
        printf("Some error occured. Maybe expression is incorrect ot not enough memory\n");
    }
    return 0;
}

void fill_screen(char screen[X][Y], struct vector expression)
{
    for (int j = 0; j < Y; ++j)
        for(int i = 0; i < X; ++i)
            screen[i][j] = '.';

    
}

void print_screen(char screen[X][Y])
{
    for (int j = 0; j < Y; ++j)
    {
        for(int i = 0; i < X; ++i)
            putchar(screen[i][j]);
        putchar('\n');
    }
}