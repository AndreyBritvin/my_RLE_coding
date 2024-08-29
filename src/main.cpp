#include <stdio.h>
#include <stdlib.h>

#include "my_rle_funcs.h"
#include "file_input.h"

#include <string.h>

int main()
{
    // char my_str[] = "aaaabbbcdeggffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffddefgelkkfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfdfd";

    code_rle("text_to_compr/to_encode.txt", "text_to_compr/coded_text.hex");

    // char my_str_2[] = "4a3b-3cde2g8f2d-5efgel2k";

    decode_rle("text_to_compr/coded_text.hex", "text_to_compr/decoded_text.txt");

    code_rle("photo_ded/image.png", "photo_ded/coded_image.hex");
    decode_rle("photo_ded/coded_image.hex", "photo_ded/image_decode.png");

    code_rle("photo_ded/cat.jpg", "photo_ded/cat_jpg.hex");
    decode_rle("photo_ded/cat_jpg.hex", "photo_ded/cat_decated.jpg");

    code_rle("photo_ded/Splash.bmp", "photo_ded/Splash_bmp.hex");
    decode_rle("photo_ded/Splash_bmp.hex", "photo_ded/desplashed.bmp");

    return EXIT_SUCCESS;
}


