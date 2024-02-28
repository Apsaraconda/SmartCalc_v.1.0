#include "calculator.h"

int calculate(char *source, double *result, unsigned Grad) {
  int error = 0;
  double temp;
  int len = strlen(source);
  char buffer[MAX_INPUT_SYM];
  Stack_num stack_num;
  stack_num_init(&stack_num);
  int i = 0;
  while (source[i] != '\0') {
    buffer[i] = source[i];
    i++;
  }
  buffer[i] = '\0';
  int position;
  position = strcspn(buffer, " ");
  int src_position = position;
  while (src_position < len && !error) {
    if (is_number(buffer[position - 1])) {
      sscanf(buffer, "%lf", &temp);
      error = push_num(&stack_num, temp);
      int i = 0;
      int src_pos_temp = src_position;
      while (source[src_pos_temp + 1] != '\0') {
        buffer[i] = source[src_pos_temp + 1];
        i++;
        src_pos_temp++;
      }
      buffer[i] = '\0';
    } else if (is_operator(buffer[position - 1]) ||
               is_func_short(buffer[position - 1])) {
      error = calc_lex(buffer[position - 1], &stack_num, &temp, Grad);
      int i = 0;
      int src_pos_temp = src_position;
      while (source[src_pos_temp + 1] != '\0') {
        buffer[i] = source[src_pos_temp + 1];
        i++;
        src_pos_temp++;
      }
      buffer[i] = '\0';
    }
    position = strcspn(buffer, " ");
    src_position += position + 1;
  }
  *result = temp;
  return error;
}

void dot_change(char *string, char symb_src, char symb_dest) {
  int k = 0;
  while ((string[k] != '\0')) {
    if (string[k] == symb_src) {
      (string[k]) = symb_dest;
    }
    k++;
  }
}



void stack_num_init(Stack_num *stack) {
  for (int i = 0; i < MAX_INPUT_SYM; i++) {
    stack->data[i] = 0;
  }
  stack->size = 0;
}

int push_num(Stack_num *stack, double value) {
  int error = 0;
  if (stack->size >= MAX_INPUT_SYM) {
    error = 1;
  } else {
    stack->data[stack->size] = value;
    stack->size++;
  }
  return error;
}

double pop_num(Stack_num *stack) {
  stack->size--;
  double number = stack->data[stack->size];
  return number;
}

// void stack_num_delete_unit(Stack_num *stack) {
//   stack->size--;
//   for (int i = 0; i < MAX_INPUT_SYM; i++) {
//     stack->data[stack->size] = '\0';
//   }
// }

void printStack_num(Stack_num *stack) {
  printf("stack_num size = %d\n", stack->size);
  for (int i = 0; i < stack->size; i++) {
    printf("<%lf>\n", stack->data[stack->size]);
  }
}

int calc_lex(char a, Stack_num *stack_num, double *result, unsigned Grad) {
  int error = 0;
  double operand_2 = pop_num(stack_num);
  ;
  switch (a) {
    case 'l':
      *result = log(operand_2);
      error = push_num(stack_num, *result);
      break;
    case 's':
      if (Grad) operand_2 = operand_2*PI/180;
      *result = sin(operand_2);
      error = push_num(stack_num, *result);
      break;
    case 'c':
      if (Grad) operand_2 = operand_2*PI/180;
      *result = cos(operand_2);
      error = push_num(stack_num, *result);
      break;
    case 't':
      if (Grad) operand_2 = operand_2*PI/180;
      *result = tan(operand_2);
      error = push_num(stack_num, *result);
      break;
    case 'g':
      *result = log10(operand_2);
      error = push_num(stack_num, *result);
      break;
    case 'a':
      if (Grad) operand_2 = operand_2*PI/180;
      *result = asin(operand_2);
      error = push_num(stack_num, *result);
      break;
    case 'o':
      if (Grad) operand_2 = operand_2*PI/180;
      *result = acos(operand_2);
      error = push_num(stack_num, *result);
      break;
    case 'n':
      if (Grad) operand_2 = operand_2*PI/180;
      *result = atan(operand_2);
      error = push_num(stack_num, *result);
      break;
    case 'q':
      *result = sqrt(operand_2);
      error = push_num(stack_num, *result);
      break;
  }
  double operand_1;
  switch (a) {
    case '^':
      operand_1 = pop_num(stack_num);
      *result = pow(operand_1, operand_2);
      error = push_num(stack_num, *result);
      break;
    case '*':
      operand_1 = pop_num(stack_num);
      *result = operand_1 * operand_2;
      error = push_num(stack_num, *result);
      break;
    case '/':
      if (operand_2 >= 0.0000001 ||
          operand_2 <= -0.0000001) {  //  деление на нуль
        operand_1 = pop_num(stack_num);
        *result = operand_1 / operand_2;
        error = push_num(stack_num, *result);
      } else {
        error = 2;
      }
      break;
    case 'm':
      operand_1 = pop_num(stack_num);
      *result = fmod(operand_1, operand_2);
      error = push_num(stack_num, *result);
      break;
    case '+':
      operand_1 = pop_num(stack_num);
      *result = operand_1 + operand_2;
      error = push_num(stack_num, *result);
      break;
    case '-':
      operand_1 = pop_num(stack_num);
      *result = operand_1 - operand_2;
      error = push_num(stack_num, *result);
      break;
  }
  return error;
}

int is_func_short(char str) {
  int result = 0;
  if (str == 's' || str == 'c' || str == 't' || str == 'a' || str == 'o' ||
      str == 'n' || str == 'q' || str == 'l' || str == 'g' || str == 'm') {
    result = 1;
  }
  return result;
}
