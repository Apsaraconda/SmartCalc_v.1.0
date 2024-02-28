#include "calculator.h"

//  Проверяет соответствие количества открывающихся скобок закрывающимся
int brackets_check(char *str) {
  int error = 0;
  int br_open_counter = 0;
  int br_close_counter = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '(') {
      br_open_counter++;
    } else if (str[i] == ')') {
      br_close_counter++;
    }
  }
  if (br_open_counter - br_close_counter != 0) {
    error = 5;
  }
  return error;
}