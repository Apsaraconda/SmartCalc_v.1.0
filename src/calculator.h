#ifndef SRC_CALCULATOR_H
#define SRC_CALCULATOR_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SYM 300
#define PI 3.14159265358980

typedef struct input_string {
  char res_str[MAX_INPUT_SYM];
  int char_counter;
  int dot_counter;
  int digit_counter;
  int operator_counter;
} in_string;

typedef struct Stack {
  char data[MAX_INPUT_SYM][MAX_INPUT_SYM * 2];
  size_t size;
  int priority[MAX_INPUT_SYM];
} Stack_t;

typedef struct Stack_number {
  double data[MAX_INPUT_SYM];
  int size;
} Stack_num;

int input_translator(char string, in_string *result);
void input_string_init(in_string *result);
void write_lex(char *str, in_string *result);
void write_operator(char str, in_string *result);
int polish_translator(char *string, char *result);
int insert_x(char *string, char *source);
void delete_button(in_string *result);
void stack_init(Stack_t *stack);
int push(Stack_t *stack, char *value, int priority);
char *pop(Stack_t *stack);
void stack_delete_unit(Stack_t *stack);
void printStack(Stack_t *stack);
int priority(char a);
int is_number(char str);
int is_function(char *str, int position, char *result);
int is_operator(char str);
int calculate(char *source, double *result, unsigned Grad);
void stack_num_init(Stack_num *stack);
int push_num(Stack_num *stack, double value);
double pop_num(Stack_num *stack);
// void stack_num_delete_unit(Stack_num *stack);
void printStack_num(Stack_num *stack);
int calc_lex(char a, Stack_num *stack_num, double *result, unsigned Grad);
int is_func_short(char str);
int brackets_check(char *str);
void is_number_polish(char *string, char *result, int *res_index, int *i);
int is_not_a_number_polish(char *string, Stack_t *stack, char *result,
                           int *res_index, int *i);
void dot_change(char *string, char symb_src, char symb_dest);
int last_sym_check(char str);

#endif  // SRC_CALCULATOR_H
