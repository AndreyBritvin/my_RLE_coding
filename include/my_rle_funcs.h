/**
 * @file my_rle_funcs.h
 * @author Andrey Britvin
 * @brief Различные операции с матрицами:
 *        Печать матрицы, сложение двух матрицей, перемножение матриц, нахождение определителя,
 *        нахождение минора элемента и применение к нему алгебраического дополнения
 *
 * @version 1.0
 * @date 2024-08-27
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef MY_ARR_FUNCS_H__
#define MY_ARR_FUNCS_H__

#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

char *code_rle(char *input_data);

char *decode_rle(char *input_data);

void flush_buffer(char char_buf[], size_t size);

void print_sequence(char to_print, char num);


#endif // MY_ARR_FUNCS_H__
