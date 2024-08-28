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

    while ((cur_symbol = input_data[iter++]) != '\0' || bef_symbol != '\0')
    {
        if (cur_symbol == bef_symbol && is_repeat)
        {
            cur_length++;
        }

        else if (cur_symbol != bef_symbol && is_repeat)
        {
            print_sequence(cur_length, bef_symbol);
            is_repeat = false;
            cur_length = 0;
            is_first_repeat = true;
        }

        else if (cur_symbol == bef_symbol && !is_repeat)
        {
            if (!is_first_repeat)
            {
                flush_buffer(cur_length, char_buf);
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
        if (cur_symbol == '\0')
        {
            break;
        }

        bef_symbol = cur_symbol;
    }

    if (is_repeat)
    {
        print_sequence(cur_length, bef_symbol);
    }
    else
    {
        flush_buffer(cur_length, char_buf);
    }

    printf("\n");

    return 0;
}

void print_sequence(char num, char to_print)
{
    printf("%d%c", num, to_print);
}

char *decode_rle(char *input_data)
{
    input_data++;
    return 0;
}

void flush_buffer(char cur_length, char char_buf[])
{
    if (cur_length == 0)
    {
        return;
    }
    printf("%d", cur_length);
    for (size_t i = 0; i<abs(cur_length); i++)
    {
        printf("%c", char_buf[i]);
        char_buf[i] = 0;
    }
}
