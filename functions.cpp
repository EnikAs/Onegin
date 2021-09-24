#include "functions.h"

int read_buffer (FILE* file_stream, char* buffer, size_t* buff_size)
{

    *buff_size = fread (buffer, sizeof(char), *buff_size, file_stream);
    if (buffer == NULL)
    {
        printf ("Input error");
    }
    int string_counter = buffer_optimise (buffer, *buff_size);
    return string_counter;
}

int buffer_optimise (char* buffer, size_t buff_size)
{
    int string_counter = 0;
    for (int i = 0 ; i < buff_size ; i ++)
    {
        if (buffer[i] == '\n')
        {
            buffer[i] = '\0';
            string_counter += 1;
        }
    }
    return  string_counter;
}

int cunt_strings(char* buffer)
{
    int string_counter = 0;
    for (int cunt = 0 ; cunt < strlen(buffer) ; cunt++)
    {
        if (buffer[cunt] == '\0')string_counter += 1;
    }
    return string_counter;
}

size_t scanf_file_size (FILE* file_stream)
{
    fseek(file_stream, 0, SEEK_END);
    size_t size_of_file = ftell(file_stream);
    fseek(file_stream, 0, SEEK_SET);
    return size_of_file;
}

int scanf_new_string (Onegin* lines, int* string_number, int* buff_char_number, char* buffer, size_t buff_size) //Íå çàáûòü ïåðåäàòü 0 â íà÷àëå !
{
    int tmp_string_len = 0;
    char tmp_symbol = buffer[*buff_char_number];
    while (tmp_symbol != '\0' )
    {

        tmp_string_len += 1;
        *buff_char_number += 1;
        tmp_symbol = buffer[*buff_char_number];

    }

    if (tmp_string_len == 0)
    {
        *buff_char_number += 1;
        if (*buff_char_number >= buff_size)
            return END_OF_FILE;
        return STRING_END;
    }
    //lines[*string_number].str = (char*) calloc(tmp_string_len, sizeof(char));
    for (int i = tmp_string_len ; i > 0 ; i--)
    {
        if (IsLetter(buffer[*buff_char_number - i]) == LETTER)
        {
            lines[*string_number].str = &buffer[*buff_char_number - tmp_string_len];
            lines[*string_number].str_lenght = tmp_string_len;
            *buff_char_number += 1;
            *string_number += 1;

            if (*buff_char_number >= buff_size)
            return END_OF_FILE;

            return CORRECT;
        }

    }
    *buff_char_number += 1;
    if (*buff_char_number >= buff_size)
            return END_OF_FILE;

    return CORRECT;
}

int scanf_all_strings (Onegin* lines, int* string_number, int* buff_char_number, char* buffer, size_t buff_size)
{
    int correct_check = DEFAULT;
    while (correct_check != END_OF_FILE)
    {

        correct_check = scanf_new_string (lines, string_number, buff_char_number, buffer, buff_size);

    }
}

int printf_all_strings (Onegin* lines, int* string_number)
{
    for (int neformal = 0 ; neformal < *string_number ; neformal++)
    {
        printf ("%s\n", lines[neformal].str);
    }
    printf ("-------------------------------------------------------------------\n");
}

int IsLetter (int letter)
{
    if ('a' <= letter && letter <= 'z' || 'A' <= letter && letter <='Z')
        return LETTER;
    else
        return NE_LETTER;
}

int trash_clean (char* str)
{
    int cunt = 0;
    while (IsLetter( str[cunt] ) == NE_LETTER)
    {
        cunt++;
        if (cunt >= strlen(str) - 1)
            break;
    }
    return cunt;
}

int trash_clean_reverse (char* str)
{
    int cunt = 0;
    size_t str_len = strlen(str);
    while ( IsLetter (str[str_len - cunt - 1]) == NE_LETTER)
        {
        cunt++;
        if (cunt >= strlen(str) - 1)
            break;
    }
    return cunt;
}

int compare_two_strings (Onegin* firstString, Onegin* secondString)
{
    size_t first = firstString->str_lenght;
    size_t second = secondString->str_lenght;
    int char1 = NULL, char2 = NULL;
    int f_step = 0, s_step = 0;

    f_step = trash_clean(firstString->str);
    s_step = trash_clean(secondString->str);

    for (int char_pos = 0 ; char_pos < std::min(first, second) - std::max(s_step, f_step) ; char_pos++)
    {
        char1 = char_pos + f_step;
        char2 = char_pos + s_step;

        if (fix_capital_letter( firstString->str[char1] ) > fix_capital_letter( secondString->str[char2]) )
            return FIRST_IS_BIGGER;
        if (fix_capital_letter( firstString->str[char1] ) < fix_capital_letter( secondString->str[char2]) )
            return SECOND_IS_BIGGER;
    }

    if (first > second)
        return FIRST_IS_BIGGER;

    else
        return SECOND_IS_BIGGER;
}

int compare_two_strings_reverse (Onegin* firstString, Onegin* secondString)
{
    int char1 = NULL, char2 = NULL;
    int f_step = 0, s_step = 0;
    size_t first = firstString->str_lenght - 1;
    size_t second = secondString->str_lenght - 1;

    f_step = trash_clean_reverse(firstString->str);
    s_step = trash_clean_reverse(secondString->str);

    for (int char_pos = 0 ; char_pos < ( std::min(first, second) - std::max(f_step, s_step) ); char_pos++)
    {
        char1 = first - char_pos - f_step;
        char2 = second - char_pos - s_step;

        if (fix_capital_letter( firstString->str[char1] ) > fix_capital_letter( secondString->str[char2]) ) return FIRST_IS_BIGGER;
        if (fix_capital_letter( firstString->str[char1] ) < fix_capital_letter( secondString->str[char2]) ) return SECOND_IS_BIGGER;
    }

    if (first > second)
        return FIRST_IS_BIGGER;

    else
        return SECOND_IS_BIGGER;


}

int comporator (const void* str1, const void* str2)
{
    int result = compare_two_strings ( ((Onegin*)str1), ((Onegin*)str2));
    if (result == FIRST_IS_BIGGER)  return 1;
    if (result == SECOND_IS_BIGGER) return -1;
    else                            return 0;

}

int comporator_reverse (const void* str1, const void* str2)
{
    int result = compare_two_strings_reverse ( ((Onegin*)str1), ((Onegin*)str2));
    if (result == FIRST_IS_BIGGER)  return 1;
    if (result == SECOND_IS_BIGGER) return -1;
    else                            return 0;

}

void sort_strings_alphabet (Onegin* stroka, int* nomer_stroki)
{   /*
    char* tmp_buffer = stroka[0].str;
    int tmp_counter = NULL;
    int lengh = NULL;
    for (int i = 0 ; i < *nomer_stroki; i++)
    {
        for (int j = 0 + i ; j < *nomer_stroki; j++)
        {
            if (compare_two_strings (stroka[j].str, tmp_buffer) == SECOND_IS_BIGGER)
            {
                tmp_buffer = stroka[j].str;
                tmp_counter = j;
            }
        }
        //printf("%s", tmp_buffer);
        stroka[tmp_counter].str = stroka[i].str;
        stroka[i].str = tmp_buffer;
        tmp_buffer = stroka[i+1].str;
        lengh = stroka[tmp_counter].str_lenght;
        stroka[tmp_counter].str_lenght = stroka[i].str_lenght;
        stroka[i].str_lenght= lengh;
        }
        */
        qsort (stroka, *nomer_stroki, sizeof(Onegin), comporator);
}

void sort_strings_alphabet_reverse (Onegin* stroka, int* nomer_stroki)
{
    /*
    char* tmp_buffer = stroka[0].str;
    int tmp_counter = NULL;
    int lengh = NULL;
    for (int i = 0 ; i < *nomer_stroki; i++)
    {
        for (int j = 0 + i ; j < *nomer_stroki; j++)
        {
            if (compare_two_strings_reverse (stroka[j].str, tmp_buffer) == SECOND_IS_BIGGER)
            {
                tmp_buffer = stroka[j].str;
                tmp_counter = j;
            }
        }
        //printf("%s", tmp_buffer);
        stroka[tmp_counter].str = stroka[i].str;
        stroka[i].str = tmp_buffer;
        tmp_buffer = stroka[i+1].str;
        lengh = stroka[tmp_counter].str_lenght;
        stroka[tmp_counter].str_lenght = stroka[i].str_lenght;
        stroka[i].str_lenght= lengh;
        } */
        qsort (stroka, *nomer_stroki, sizeof(Onegin), comporator_reverse);
}

int fix_capital_letter (int c)
{
    if (c >= 'A' && c <= 'Z' )
        return c + 'a' - 'A';
    else
        return c;
}

void printf_first_variant (int* buff_char_number, char* buffer, size_t buff_size)
{
    *buff_char_number = 0;
    int correct_check = DEFAULT;
    while (correct_check != END_OF_FILE)
    {

        correct_check = printf_first_varinat_string (buff_char_number, buffer, buff_size);

    }

}

int printf_first_varinat_string (int* buff_char_number, char* buffer, size_t buff_size) //Íå çàáûòü ïåðåäàòü 0 â íà÷àëå !
{
    int tmp_string_len = 0;
    char tmp_symbol = buffer[*buff_char_number];
    while (tmp_symbol != '\0' )
    {

        tmp_string_len += 1;
        *buff_char_number += 1;
        tmp_symbol = buffer[*buff_char_number];

    }

    if (tmp_string_len == 0)
        {
            *buff_char_number += 1;
                return STRING_END;
        }

    for (int i = tmp_string_len ; i > 0 ; i--)
    {
        if (IsLetter(buffer[*buff_char_number - i]) == LETTER)
        {
            printf("%s\n", &buffer[*buff_char_number - tmp_string_len]);
            *buff_char_number += 1;
            if (*buff_char_number >= buff_size)
                return END_OF_FILE;

            return CORRECT;
        }

    }

    *buff_char_number += 1;

    if (*buff_char_number >= buff_size)
            return END_OF_FILE;

    return CORRECT;
}
