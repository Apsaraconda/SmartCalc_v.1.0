#include "calculator.h"

//  Перевод инфиксной нотации в обратную польскую
int polish_translator(char *string, char *result) {
  int error = 0;
  int res_index = 0;
  result[res_index] = '\0';
  for (int i = 0; i < MAX_INPUT_SYM; i++) {
    result[i] = '\0';
  }
  Stack_t stack;
  stack_init(&stack);
  if (string[0] != '\0') {
    for (int i = 0; string[i] != '\0'; i++) {
      if (is_number(string[i])) {  // числа помещаем на выход в строку result
        is_number_polish(string, result, &res_index, &i);
      } else {
        error = is_not_a_number_polish(string, &stack, result, &res_index, &i);
        if ((string[i + 1] == '\0') && last_sym_check(string[i])) error = 6;
      }
      if (error) break;
    }
  }
  result[res_index] = '\0';
  while (stack.size) {
    strcat(result, pop(&stack));
  }
  return error;
}

void is_number_polish(char *string, char *result, int *res_index, int *i) {
  char temp_str[MAX_INPUT_SYM * 2];
  int dot_counter = 0;
  if (string[*i] == '.' || string[*i] == ',') {
    dot_counter++;
    string[*i] = ',';
  }
  int j = 0;
  int after_dot_counter = 0;  //  счетчик считываемых цифр после запятой
  temp_str[j] = string[*i];
  while (is_number(string[*i + 1]) &&
         after_dot_counter <
             9) {  //  ограничение на количество считываемых цифр после запятой
    if ((string[*i + 1] == '.' || string[*i + 1] == ',') && dot_counter > 0) {
      *i = *i + 1;
      string[*i] = ',';
    } else {
      *i = *i + 1;
      j++;
      if (string[*i] == '.' || string[*i] == ',') {
        dot_counter++;
        string[*i] = ',';
      }
      if (dot_counter > 0) after_dot_counter++;
      temp_str[j] = string[*i];
    }
  }
  while (is_number(string[*i]) &&
         after_dot_counter >
             0) {  //  пропуск цифр после запятой исходной строки
    if (is_number(string[*i + 1])) {
      *i = *i + 1;
    } else {
      break;
    }
  }
  temp_str[j + 1] = ' ';
  temp_str[j + 2] = '\0';
  j = 0;
  while (temp_str[j] != '\0') {
    result[*res_index] = temp_str[j];
    j++;
    *res_index = *res_index + 1;
  }
  result[*res_index] = '\0';
}

int is_not_a_number_polish(char *string, Stack_t *stack, char *result,
                           int *res_index, int *i) {
  int error = 0;
  char temp_func_str[4];
  int parsed_symbols = is_function(string, *i, temp_func_str);
  if (parsed_symbols) {
    if (((temp_func_str[0] == 'm') &&
         (!is_number(string[*i - 1]) &&
          string[*i - 1] != ')'))  //  если перед mod нет числа или )
        || (parsed_symbols == 2 &&
            (!is_number(string[*i + 2]) && string[*i + 2] != '(' &&
             string[*i + 2] != '-' && string[*i + 2] != '+')) ||
        (parsed_symbols == 3 &&
         (!is_number(string[*i + 3]) && string[*i + 3] != '(' &&
          string[*i + 3] != '-' && string[*i + 3] != '+')) ||
        (parsed_symbols == 4 &&
         (!is_number(string[*i + 4]) && string[*i + 4] != '(' &&
          string[*i + 4] != '-' && string[*i + 4] != '+')))
      error = 6;
    if (!error) {
      if (stack->priority[stack->size - 1] >= priority(temp_func_str[0]) &&
          (stack->priority[stack->size - 1] != 5)) {  //  для случая со скобками
        if (stack->size) strcat(result, pop(stack));
      }
      error = push(stack, temp_func_str, priority(temp_func_str[0]));
      *i = *i + parsed_symbols - 1;
    }
  } else {
    if (is_operator(string[*i])) {
      if ((string[*i] == '-' ||
           string[*i] == '+')  //  проверка на унарный + и -
          && (!string[*i - 1] ||
              (string[*i - 1] && !is_number(string[*i - 1]) &&
               (string[*i - 1]) != ')'))) {  //  string должен быть без пробелов
        strcat(result, "0 ");  //  записываем 0 перед унарным + или -
        *res_index = *res_index + 2;
      }
      temp_func_str[0] = string[*i];
      temp_func_str[1] = ' ';
      temp_func_str[2] = '\0';
      if (stack->priority[stack->size - 1] >= priority(string[*i]) &&
          (stack->priority[stack->size - 1] != 5) &&
          string[*i] != ')') {  //  для случая со скобками
        if (stack->size) {
          strcat(result, pop(stack));
          *res_index = *res_index + 2;
        }
        error = push(stack, temp_func_str, priority(temp_func_str[0]));
      } else if (string[*i] ==
                 ')') {  //  если попалась ), записываем на выход все до (
        if (stack->size > 0) {
          while (stack->size && stack->data[stack->size - 1][0] != '(') {
            strcat(result, pop(stack));
            *res_index = *res_index + 2;
          }
          stack_delete_unit(stack);  //  очищаем ( из стека
        } else {
          error = 6;
        }
      } else {
        error = push(stack, temp_func_str, priority(temp_func_str[0]));
      }
      if (string[*i] == 'm') i = i + 2;
    }
  }
  return error;
}

int is_number(char str) {
  int res = 0;
  if ((str >= '0' && str <= '9') || str == '.' || str == ',') {
    res = 1;
  } else if (str == 'x') {
    res = 2;
  }
  return res;
}

int is_function(char *str, int pos, char *result) {
  int flag = 0;
  if (str[pos] == 'c' && str[pos + 1] == 'o' && str[pos + 2] == 's') {
    flag = 3;
    strcpy(result, "c ");
  } else if (str[pos] == 's' && str[pos + 1] == 'i' && str[pos + 2] == 'n') {
    flag = 3;
    strcpy(result, "s ");
  } else if (str[pos] == 't' && str[pos + 1] == 'a' && str[pos + 2] == 'n') {
    flag = 3;
    strcpy(result, "t ");
  } else if (str[pos] == 'a' && str[pos + 1] == 'c' && str[pos + 2] == 'o' &&
             str[pos + 3] == 's') {
    flag = 4;
    strcpy(result, "o ");
  } else if (str[pos] == 'a' && str[pos + 1] == 's' && str[pos + 2] == 'i' &&
             str[pos + 3] == 'n') {
    flag = 4;
    strcpy(result, "a ");
  } else if (str[pos] == 'a' && str[pos + 1] == 't' && str[pos + 2] == 'a' &&
             str[pos + 3] == 'n') {
    flag = 4;
    strcpy(result, "n ");
  } else if (str[pos] == 's' && str[pos + 1] == 'q' && str[pos + 2] == 'r' &&
             str[pos + 3] == 't') {
    flag = 4;
    strcpy(result, "q ");
  } else if (str[pos] == 'l' && str[pos + 1] == 'n') {
    flag = 2;
    strcpy(result, "l ");
  } else if (str[pos] == 'l' && str[pos + 1] == 'o' && str[pos + 2] == 'g') {
    flag = 3;
    strcpy(result, "g ");
    // } else if (str[pos] == 'm' && str[pos + 1] == 'o' && str[pos + 2] == 'd')
    // {
    //   flag = 3;
    //   strcpy(result, "m ");
  } else {
    flag = 0;
  }
  return flag;
}

int is_operator(char str) {
  int result = 0;
  if (str == '^' || str == '+' || str == '-' || str == '*' || str == '/' ||
      str == 'm') {
    result = 1;
  } else if (str == '(' || str == ')') {
    result = 2;
  }
  return result;
}

int last_sym_check(char str) {
  int result = 0;
  if (str == '^' || str == '+' || str == '-' || str == '*' || str == '/' ||
      str == '(') {
    result = 1;
  }
  return result;
}

void stack_init(Stack_t *stack) {
  for (int i = 0; i < MAX_INPUT_SYM; i++) {
    for (int j = 0; j < MAX_INPUT_SYM * 2; j++) {
      stack->data[i][j] = '\0';
    }
    stack->priority[i] = 0;
  }
  stack->size = 0;
}

int push(Stack_t *stack, char *value, int priority) {
  int error = 0;
  if (stack->size >= MAX_INPUT_SYM) {
    error = 1;
  } else {
    for (int i = 0; value[i] != '\0'; i++) {
      stack->data[stack->size][i] = value[i];
    }
    stack->priority[stack->size] = priority;
    stack->size++;
  }
  return error;
}

char *pop(Stack_t *stack) {
  stack->size--;
  char *pop_str = stack->data[stack->size];
  stack->priority[stack->size] = 0;
  return pop_str;
}

void stack_delete_unit(Stack_t *stack) {
  stack->size--;
  stack->priority[stack->size] = 0;
  for (int i = 0; i < MAX_INPUT_SYM; i++) {
    stack->data[stack->size][i] = '\0';
  }
}

void printStack(Stack_t *stack) {
  int i;
  int len = stack->size;
  printf("stack size = %ld\n", stack->size);
  for (i = 0; i < len; i++) {
    printf("<%s>", stack->data[i]);
    printf(" | ");
    printf("priority[%d] = %d\n", i, stack->priority[i]);
  }
}

int priority(char a) {
  int result = 0;
  switch (a) {
    case '(':
    case ')':
      result = 5;
      break;
    case '^':
      result = 4;
      break;
    case 'l':
    case 's':
    case 'c':
    case 't':
    case 'g':
    case 'a':
    case 'o':
    case 'n':
    case 'q':
      result = 3;
      break;
    case '*':
    case '/':
    case 'm':
      result = 2;
      break;
    case '-':
    case '+':
      result = 1;
      break;
  }
  return result;
}