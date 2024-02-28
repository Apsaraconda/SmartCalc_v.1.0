#include "calculator.h"

//  Функция удаляет с конца строки символы по лексемам, либо один символ из
//  result->res_str
void delete_button(in_string *result) {
  int success = 0;
  int len = strlen(result->res_str);
  if (len >= 2) {
    if (result->res_str[result->char_counter - 2] == 'l' &&
        result->res_str[result->char_counter - 1] == 'n') {
      for (int i = 1; i < 3; i++) {
        result->res_str[result->char_counter - i] = '\0';
      }
      result->char_counter -= 2;
      success++;
    }
  }
  if (len >= 4 && !success) {
    if ((result->res_str[result->char_counter - 4] == 'a' &&
         result->res_str[result->char_counter - 3] == 's' &&
         result->res_str[result->char_counter - 2] == 'i' &&
         result->res_str[result->char_counter - 1] == 'n') ||
        (result->res_str[result->char_counter - 4] == 'a' &&
         result->res_str[result->char_counter - 3] == 'c' &&
         result->res_str[result->char_counter - 2] == 'o' &&
         result->res_str[result->char_counter - 1] == 's') ||
        (result->res_str[result->char_counter - 4] == 'a' &&
         result->res_str[result->char_counter - 3] == 't' &&
         result->res_str[result->char_counter - 2] == 'a' &&
         result->res_str[result->char_counter - 1] == 'n') ||
        (result->res_str[result->char_counter - 4] == 's' &&
         result->res_str[result->char_counter - 3] == 'q' &&
         result->res_str[result->char_counter - 2] == 'r' &&
         result->res_str[result->char_counter - 1] == 't')) {
      for (int i = 1; i < 5; i++) {
        result->res_str[result->char_counter - i] = '\0';
      }
      result->char_counter -= 4;
      success++;
    }
  }
  if (len >= 3 && !success) {
    if ((result->res_str[result->char_counter - 3] == 's' &&
         result->res_str[result->char_counter - 2] == 'i' &&
         result->res_str[result->char_counter - 1] == 'n') ||
        (result->res_str[result->char_counter - 3] == 'c' &&
         result->res_str[result->char_counter - 2] == 'o' &&
         result->res_str[result->char_counter - 1] == 's') ||
        (result->res_str[result->char_counter - 3] == 't' &&
         result->res_str[result->char_counter - 2] == 'a' &&
         result->res_str[result->char_counter - 1] == 'n') ||
        (result->res_str[result->char_counter - 3] == 'm' &&
         result->res_str[result->char_counter - 2] == 'o' &&
         result->res_str[result->char_counter - 1] == 'd') ||
        (result->res_str[result->char_counter - 3] == 'l' &&
         result->res_str[result->char_counter - 2] == 'o' &&
         result->res_str[result->char_counter - 1] == 'g')) {
      for (int i = 1; i < 4; i++) {
        result->res_str[result->char_counter - i] = '\0';
      }
      result->char_counter -= 3;
      success++;
    }
  }
  if (!success) {
    result->res_str[result->char_counter - 1] = '\0';
    result->char_counter--;
  }
}
