#ifndef EXPRESSION_PROCESS_H
#define EXPRESSION_PROCESS_H

#include "structs.h"

char* get_lexem(char* str, struct expr_item* answer, int has_left_operand);

struct vector expression_to_postfix(char* str); //если введенное выражение некорректно, вернет невалидный вектор
// Есть функция vector_is_valid, которая это и проверяет
// Также может быть невалидным если закончилась память, но разницы нет, мы работать не можем, выводи просто, что произошла ошибка

double calculate_expression(struct vector expression, double x);

#endif