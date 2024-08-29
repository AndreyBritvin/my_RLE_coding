#include "my_rle_funcs.h"

int code_rle(char *input_data)
{
    size_t iter = 1;

    char cur_length = 1;
    char bef_symbol = input_data[0];
    char cur_symbol = 0;

    bool is_repeat = input_data[0] == input_data[1];
    bool is_first_repeat = false;

    char char_buf[128] = {};

    FILE *file_ptr = NULL;
    char filename[] = "coded_text.hex";
    if (int err_num = open_file(&file_ptr, filename, "w+b"))
    {
        return err_num;
    }

    while ((cur_symbol = input_data[iter++]) != '\0' || bef_symbol != '\0')
    {
        if (cur_symbol == bef_symbol && is_repeat) // Одинаково и повторяется
        {
            cur_length++; // прибавляем к длине последовательность
        }

        else if (cur_symbol != bef_symbol && is_repeat) // Закончился повтор
        {
            print_sequence(cur_length, bef_symbol, &file_ptr); // Печатаем сколько надо символов
            is_repeat = false; // Обнуляемся
            cur_length = 0;
            is_first_repeat = true;
        }

        else if (cur_symbol == bef_symbol && !is_repeat) // Если снова последовательные символы
        {
            if (!is_first_repeat) // Если до этого была не повторяющаяся последовательность
            {
                flush_buffer(cur_length, char_buf, &file_ptr); // То очистить буффер
            }

            is_repeat = true;
            cur_length = 2; // последовательность с 2х начинается
        }

        else if (cur_symbol != bef_symbol && !is_repeat) // Если последовательность неповторяющихся символов
        {
            if (is_first_repeat) // Действительно ли это были неповторяющиеся?
            {
                is_first_repeat = false; // Да!
            }
            char_buf[abs(cur_length--)] = bef_symbol; // Запоминаем в буффер символы и их длину
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
        print_sequence(cur_length, bef_symbol, &file_ptr);
    }
    else
    {
        flush_buffer(cur_length, char_buf, &file_ptr);
    }

    printf("\n");

    if (int err_num = close_file(&file_ptr))
    {
        return err_num;
    }

    return 0;
}

void print_sequence(char num, char to_print, FILE **file_ptr)
{
    // printf("%d%c", num, to_print);
    fprintf(*file_ptr, "%c%c", num, to_print);
}

int decode_rle()
{
    char cur_length = 1;
    char cur_symbol = 0;

    char char_buf[128] = {};

    FILE *file_ptr_input = NULL;
    char filename_input[] = "coded_text.hex";

    FILE *file_ptr_output = NULL;
    char filename_output[] = "decoded_text.text";

    if (int err_num = open_file(&file_ptr_output, filename_output, "w+b"))
    {
        return err_num;
    }

    if (int err_num = open_file(&file_ptr_input, filename_input, "rb"))
    {
        return err_num;
    }

    while (fscanf(file_ptr_input, "%c", &cur_length) != EOF)
    {
        if (cur_length >= 0)
        {
            fscanf(file_ptr_input, "%c", &cur_symbol);
            for (char i = 0; i < cur_length; i++)
            {
                printf("%c", cur_symbol);
            }
        }
        else
        {
            for (char i = 0; i < abs(cur_length); i++)
            {
                fscanf(file_ptr_input, "%c", &cur_symbol);
                printf("%c", cur_symbol);
            }
        }
    }

    if (int err_num = close_file(&file_ptr_input))
    {
        return err_num;
    }
    if (int err_num = close_file(&file_ptr_output))
    {
        return err_num;
    }

    return 0;
}

void flush_buffer(char cur_length, char char_buf[], FILE **file_ptr)
{
    if (cur_length == 0)
    {
        return;
    }
    // printf("%d", cur_length);
    fprintf(*file_ptr, "%c", cur_length);

    for (size_t i = 0; i < abs(cur_length); i++)
    {
        // printf("%c", char_buf[i]);
        fprintf(*file_ptr, "%c", char_buf[i]);
        char_buf[i] = 0;
    }
}
