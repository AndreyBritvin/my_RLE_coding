#include "my_rle_funcs.h"

int code_rle(char input_data[], char output_data[])
{
    FILE *file_ptr_inp = NULL;
    char filemode_input[] = "rb";
    if (int err_num = open_file(&file_ptr_inp, input_data, filemode_input))
    {
        return err_num;
    }

    FILE *file_ptr = NULL;
    char filemode_output[] = "w+b";
    if (int err_num = open_file(&file_ptr, output_data, filemode_output))
    {
        return err_num;
    }

    // size_t iter = 1;

    char bef_symbol = 0;
    char cur_symbol = 0;

    fread((void*)&bef_symbol, sizeof(char), 1, file_ptr_inp);
    fread((void*)&cur_symbol, sizeof(char), 1, file_ptr_inp);

    ungetc(cur_symbol, file_ptr_inp);

    bool is_repeat = bef_symbol == cur_symbol;
    char cur_length = is_repeat;
    bool is_first_repeat = false;

    char char_buf[128] = {};

    // while ((cur_symbol = input_data[iter++]) != '\0' || bef_symbol != '\0')
    while (fread(&cur_symbol, sizeof(char), 1, file_ptr_inp))
    {
        // printf("%c\n", cur_symbol);
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

        // Обработка переполнения байта с длиной
        if (cur_length == 127)
        {
            print_sequence(cur_length, bef_symbol, &file_ptr); // Печатаем сколько надо символов
            cur_length = 0; // Обнуляемся
        }
        else if (cur_length == -127)
        {
            flush_buffer(cur_length, char_buf, &file_ptr);
            cur_length = 0; // Обнуляемся
        }

        // printf("bc = %c, cc = %c\n", bef_symbol, cur_symbol);
        // if (cur_symbol == '\0')
        // {
            // break;
        // }

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
    if (int err_num = close_file(&file_ptr_inp))
    {
        return err_num;
    }

    return 0;
}


int decode_rle(char input_data[], char output_data[])
{
    char cur_length = 1;
    char cur_symbol = 0;

    // char char_buf[128] = {};

    FILE *file_ptr_input = NULL;
    char filemode_input[] = "rb";

    FILE *file_ptr_output = NULL;
    char filemode_output[] = "w+b";

    if (int err_num = open_file(&file_ptr_output, output_data, filemode_output))
    {
        return err_num;
    }

    if (int err_num = open_file(&file_ptr_input, input_data, filemode_input))
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
                fwrite(&cur_symbol, sizeof(char), 1, file_ptr_output);
            }
        }
        else
        {
            for (char i = 0; i < abs(cur_length); i++)
            {
                fscanf(file_ptr_input, "%c", &cur_symbol);
                printf("%c", cur_symbol);
                fwrite(&cur_symbol, sizeof(char), 1, file_ptr_output);
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

void print_sequence(char num, char to_print, FILE **file_ptr)
{
    // printf("%d%c", num, to_print);
    // fprintf(*file_ptr, "%c%c", num, to_print);
    fwrite(&num, sizeof(char), 1, *file_ptr);
    fwrite(&to_print, sizeof(char), 1, *file_ptr);
}

void flush_buffer(char cur_length, char char_buf[], FILE **file_ptr)
{
    if (cur_length == 0)
    {
        return;
    }
    // printf("%d", cur_length);
    // fprintf(*file_ptr, "%c", cur_length);
    fwrite(&cur_length, sizeof(char), 1, *file_ptr);
    for (size_t i = 0; i < abs(cur_length); i++)
    {
        // printf("%c", char_buf[i]);
        // fprintf(*file_ptr, "%c", char_buf[i]);
        fwrite(&char_buf[i], sizeof(char), 1, *file_ptr);
        char_buf[i] = 0;
    }
}
