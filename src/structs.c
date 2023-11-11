#include "structs.h"
#include <stdlib.h>

struct stack* stack_init()
{
    struct stack* res = malloc(sizeof(struct stack));
    res->down = NULL;
    return res;
}

void stack_push(struct stack** top, struct expr_item val)
{
    struct stack* tmp = malloc(sizeof(struct stack));
    if (tmp != NULL)
    {
        tmp->down = *top;
        tmp->data = val;
        *top = tmp;
    }
}

struct expr_item stack_top(struct stack* top)
{
    return top->data;
}

void stack_pop(struct stack** top)
{
    struct stack *tmp = *top;
    *top = (*top)->down;
    free(tmp);
}

int stack_is_empty(struct stack* top)
{
    return top->down == NULL;
}

void stack_destroy(struct stack* top)
{
    if (top != NULL)
    {
        struct stack* tmp = top->down;
        free(top);
        stack_destroy(tmp);
    }
}

//-------------------

struct vector vector_init()
{
    struct vector res;
    res.data = malloc(10 * sizeof(struct expr_item));
    res.size = 0;
    res.capacity = 10;
    return res;
}

int vector_is_valid(struct vector* vec)
{
    return vec->data != NULL;
}

void vector_realloc(struct vector* vec)
{

}

void vector_push_back(struct vector* vec, struct expr_item item)
{

}

struct expr_item vector_get_elem(struct vector* vec, int index)
{
    return vec->data[index];
}

void vector_destroy(struct vector* vec)
{
    free(vec->data);
}