#include "calculator.h"

//  Функция находит x в тексте source и вставляет вместо него произвольную
//  строку string Копирует получившийся текст в массив src_struct->input_res_str
//  Присваивает src_struct->char_counter длину строки source
int insert_x(char *string, char *source) {
  int error = 0;
  int len_str = strlen(string);
  int len_src = strlen(source);
  int position = 0;
  if (len_str + len_src <= MAX_INPUT_SYM) {
    for (int i = 0; string[i] != '\0'; i++) {
      if ((string[i] < '0' || string[i] > '9') && string[i] != '.' &&
          string[i] != ',' && string[i] != '+' && string[i] != '-') {
        error++;
      }
    }
    if (!error) {
      position = strcspn(source, "x");
      while (position < len_src &&
             !error) {  //  Если x находится не в конце строки
        if (string[0] != '\0') {
          char buffer[MAX_INPUT_SYM];
          int buf_index = 0;
          for (int i = 0; i < MAX_INPUT_SYM; i++) {
            buffer[i] = '\0';
          }
          int position_copy = position;
          while (position_copy + 1 != len_src &&
                 source[position_copy + 1] !=
                     '\0') {  //  Копируем остаток source в buffer
            buffer[buf_index] = source[position_copy + 1];
            buf_index++;
            position_copy++;
          }
          buffer[buf_index] = '\0';
          position_copy = position;
          source[position_copy] = '(';
          position_copy++;
          for (int i = 0; string[i] != '\0';
               i++) {  //  Вставляем string вместо x
            source[position_copy] = string[i];
            position_copy++;
          }
          source[position_copy] = ')';
          position_copy++;
          source[position_copy] = '\0';
          if ((position_copy + strlen(buffer)) <= MAX_INPUT_SYM) {
            strcat(source, buffer);  //  Вставляем остаток в source из buffer
          } else {
            error = 1;
          }
        } else {
          error = 4;  //  пустой x
        }
        position = strcspn(source, "x");
      }
    } else {
      error = 3;  //  x неправильно записан
    }
  } else {
    error = 1;
  }
  return error;
}
