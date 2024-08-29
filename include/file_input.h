#ifndef FILE_INPUT_H__
#define FILE_INPUT_H__

#include <stdio.h>
#include <errno.h>

int open_file(FILE **file_ptr, char filename[], char mode[]);

int close_file(FILE **file_ptr);

#endif // FILE_INPUT_H__
