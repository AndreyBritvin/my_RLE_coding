#include "my_rle_funcs.h"

char *code_rle(char *input_data)
{
    size_t iter = 1;

    char cur_length = 1;
    char bef_symbol = input_data[0];
    char cur_symbol = 0;

    bool is_repeat = input_data[0] == input_data[1];
    bool is_first_repeat = false;

    size_t buf_iter = 0;
    char char_buf[128] = {};

    while ((cur_symbol = input_data[iter++]) != '\0')
    {
        if (cur_symbol == bef_symbol && is_repeat)
        {
            cur_length++;
        }

        else if (cur_symbol != bef_symbol && is_repeat)
        {
            printf("%d%c", cur_length, bef_symbol);
            is_repeat = false;
            cur_length = 0;
            is_first_repeat = true;
        }

        else if (cur_symbol == bef_symbol && !is_repeat)
        {
            if (!is_first_repeat)
            {
                printf("%d", cur_length);
                for (size_t i = 0; i<abs(cur_length); i++)
                {
                    printf("%c", char_buf[i]);
                    char_buf[i] = 0;
                }
            }

            is_repeat = true;
            cur_length = 2;
        }

        else if (cur_symbol != bef_symbol && !is_repeat)
        {
            if (is_first_repeat)
            {
                is_first_repeat = false;
            }
            char_buf[abs(cur_length--)] = bef_symbol;
        }



        // printf("bc = %c, cc = %c\n", bef_symbol, cur_symbol);

        bef_symbol = cur_symbol;
    }

    printf("\n");

    return 0;
}

void print_sequence(char to_print, char num)
{
    printf("%d%c", to_print, num);
}

char *decode_rle(char *input_data)
{
    input_data++;
    return 0;
}

void flush_buffer(char char_buf[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%c", char_buf[i]);
        if (char_buf[i] == '\0')
        {
            break;
        }
        char_buf[i] = 0;
    }
}
