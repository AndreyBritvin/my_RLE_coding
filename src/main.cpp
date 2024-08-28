#include <stdio.h>
#include <stdlib.h>

#include "my_rle_funcs.h"
#include <string.h>

int main()
{
    char my_str[] = "aaaabbbcdeggffffffff";

    code_rle(my_str);

    return EXIT_SUCCESS;
}
