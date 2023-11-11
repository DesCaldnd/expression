enum oper_type
{
    PLUS, UN_MINUS, BIN_MINUS, MULTIPLY, DIVIDE, OPEN_B, CLOSE_B, SIN, COS, TAN, CTG, SQRT, LN, VARIABLE, CONSTANT, UNDEF
};

struct stack
{
    struct expr_item data;
    struct stack* down;
};

struct vector
{
    struct expr_item* data;
    int size;
    int capacity;
};

struct expr_item
{
    enum oper_type type;
    double value; // на случай если это константа
    int (*calculate)(struct expr_item, struct stack*, double x); //указатель на функцию которая будет все вычислять
};