enum oper_type
{
    PLUS, UN_MINUS, BIN_MINUS, MULTIPLY, DIVIDE, OPEN_B, CLOSE_B, SIN, COS, TAN, CTG, SQRT, LN, VARIABLE, CONSTANT, UNDEF
};

struct expr_item;

struct stack
{
    struct expr_item data;
    struct stack* down;
};

struct stack* stack_init();
void stack_push(struct stack** top, struct expr_item val);
struct expr_item stack_top(struct stack* top);
void stack_pop(struct stack** top);
int stack_is_empty(struct stack* top);
void stack_destroy(struct stack* top);

struct vector
{
    struct expr_item* data;
    int size;
    int capacity;
};

struct vector* vector_init();
int vector_is_valid(struct vector* vec);
void vector_realloc(struct vector* vec);
void vector_push_back(struct vector* vec, struct expr_item item);
struct expr_item vector_get_elem(struct* vec, int index);
void vector_destroy(struct vector* vec);

struct expr_item
{
    enum oper_type type;
    double value; // на случай если это константа
    int (*calculate)(struct expr_item, struct stack*, double x); //указатель на функцию которая будет все вычислять
};