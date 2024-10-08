#include "file_input.h"

int open_file(FILE **file_ptr, char filename[], char mode[])
{
    if ((*file_ptr = fopen(filename, mode)) == NULL)
    {
        printf("Error in opening file %s\n", filename);

        return errno;
    }

    return 0;
}

int close_file(FILE **file_ptr)
{
    if (fclose(*file_ptr) != 0)
    {
        printf("Error in closing file\n");

        return errno;
    }

    return 0;
}
