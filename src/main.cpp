#include <stdio.h>
#include <stdlib.h>

#include "my_rle_funcs.h"
#include "file_input.h"

#include <string.h>

int main()
{
    char my_str[] = "aaaabbbcdeggffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffddefgelkkfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfd";

    code_rle(my_str);

    char my_str_2[] = "4a3b-3cde2g8f2d-5efgel2k";

    decode_rle();

    return EXIT_SUCCESS;
}


