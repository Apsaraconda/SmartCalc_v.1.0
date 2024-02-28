#include "calculator.h"

//  Функция присваивает нули данным в структуре in_string *result
void input_string_init(in_string *result) {
  for (int i = 0; i < MAX_INPUT_SYM; i++) {
    result->res_str[i] = '\0';
  }
  result->char_counter = 0;
  result->digit_counter = 0;
  result->operator_counter = 0;
  result->dot_counter = 0;
}

//  Функция добавляет в массив result->res_str символы по лексемам
//  которые выбираются в соответствии с поступаемым символам string
int input_translator(char string, in_string *result) {
  int error = 0;
  if (result->char_counter < MAX_INPUT_SYM - 1) {
    if (string == 's' || string == 'c' || string == 't' || string == 'm' ||
        string == 'g') {
      char write4[5] = "sin(";
      if (string == 'c') strcpy(write4, "cos(");
      if (string == 't') strcpy(write4, "tan(");
      if (string == 'm') strcpy(write4, "mod(");
      if (string == 'g') strcpy(write4, "log(");
      if (result->char_counter < MAX_INPUT_SYM - 4) {
        if ((is_operator(result->res_str[result->char_counter - 1]) ||
             result->res_str[result->char_counter - 1] == '(' ||
             (result->char_counter == 0)) &&
            (result->res_str[result->char_counter - 1] != ')') &&
            (string != 'm') &&
            !is_number(result->res_str[result->char_counter - 1])) {
          write_lex(write4, result);
        } else if ((string == 'm') &&
                   ((result->res_str[result->char_counter - 1] == ')') ||
                    is_number(result->res_str[result->char_counter - 1]))) {
          write_lex(write4, result);
        }
      } else {
        error = 1;
      }
    } else if (string == 'a' || string == 'o' || string == 'n' ||
               string == 'q') {
      char write5[6] = "asin(";
      if (string == 'o') strcpy(write5, "acos(");
      if (string == 'n') strcpy(write5, "atan(");
      if (string == 'q') strcpy(write5, "sqrt(");
      if (result->char_counter < MAX_INPUT_SYM - 5) {
        if ((is_operator(result->res_str[result->char_counter - 1]) ||
             result->res_str[result->char_counter - 1] == '(' ||
             (result->char_counter == 0)) &&
            (result->res_str[result->char_counter - 1] != ')') &&
            !is_number(result->res_str[result->char_counter - 1])) {
          write_lex(write5, result);
        }
      } else {
        error = 1;
      }
    } else if (string == 'l') {
      if (result->char_counter < MAX_INPUT_SYM - 3) {
        if ((is_operator(result->res_str[result->char_counter - 1]) ||
             result->res_str[result->char_counter - 1] == '(' ||
             (result->char_counter == 0)) &&
            (result->res_str[result->char_counter - 1] != ')') &&
            (!is_number(result->res_str[result->char_counter - 1]))) {
          char ln[4] = "ln(";
          write_lex(ln, result);
        }
      } else {
        error = 1;
      }
    } else if (string == ',') {
      if (result->dot_counter == 0) {  //  если еще не вводили .
        result->res_str[result->char_counter] = ',';
        result->char_counter++;
        result->dot_counter++;
      }
    } else if ((string >= '0' && string <= '9' &&
                result->res_str[result->char_counter - 1] != 'x' &&
                result->res_str[result->char_counter - 1] != ')')) {
      result->res_str[result->char_counter] = string;
      result->char_counter++;
      result->operator_counter = 0;
      result->digit_counter++;
    } else if (string == 'x' &&
               (!is_number(result->res_str[result->char_counter - 1]))) {
      result->res_str[result->char_counter] = string;
      result->char_counter++;
      result->operator_counter = 0;
      result->digit_counter++;
    } else if (is_operator(string) == 1) {  //  если вводим оператор
      if (is_number(result->res_str[result->char_counter - 1]) ||
          result->res_str[result->char_counter - 1] ==
              ')') {  //  если вводим после чисел или скобок
        write_operator(string, result);
      } else if (is_operator(result->res_str[result->char_counter - 1]) ==
                 1) {  //  если уже вводили оператор
        if ((result->res_str[result->char_counter - 2]) != '(' ||
            (result->res_str[result->char_counter - 1])) {
          result->char_counter--;
          result->res_str[result->char_counter] = string;
          result->char_counter++;
        }
      } else if ((result->res_str[result->char_counter - 1] == '(') ||
                 !(result->res_str[result->char_counter])) {  //  если еще не
                                                              //  ввели число
        if (string == '+' || string == '-') {  //  записываем + или -
          write_operator(string, result);
        }
      }
    } else if (is_operator(string) == 2) {  //  если вводим оператор
      if (string == '(') {
        if (!is_number(result->res_str[result->char_counter - 1]) &&
            (result->res_str[result->char_counter - 1] != ')'))
          write_operator(string, result);
      } else {  // (string == ')')
        if ((result->res_str[result->char_counter - 1]) != '(' &&
            result->char_counter != 0)
          write_operator(string, result);
      }
    }
  } else {
    error = 1;
  }
  return error;
}

void write_lex(char *str, in_string *result) {
  for (int i = 0; str[i] > '\0' && str[i] < '\177'; i++) {
    result->res_str[result->char_counter] = str[i];
    result->char_counter++;
  }
  result->digit_counter = 0;
  result->dot_counter = 0;
  result->operator_counter = 0;
}

void write_operator(char str, in_string *result) {
  result->res_str[result->char_counter] = str;
  result->char_counter++;
  result->operator_counter++;
  result->dot_counter = 0;
  result->digit_counter = 0;
}
