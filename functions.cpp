#include "functions.h"
 /*
void fix_buffer_size (int* buffer_size, char* buffer)
{
    for (int cunt = 0 ; cunt < *buffer_size ; cunt ++ )
    {
        if ( buffer[cunt] == '\n' ) *buffer_size -= 1;
    }
}
 */
void scanf_buffer (FILE* file_stream, char* buffer, size_t* buffer_size)
{

    *buffer_size = fread (buffer, sizeof(char), *buffer_size, file_stream);
    if (buffer == NULL)
    {
        printf ("Input error");
    }
    buffer_optimise (buffer, *buffer_size);
}

void buffer_optimise (char* buffer, size_t buffer_size)
{
    for (int i = 0 ; i < buffer_size ; i ++)
        if (buffer[i] == '\n')buffer[i] = '\0';
}

int cunt_strings(char* buffer)
{
    int string_counter = 0;
    for (int cunt = 0 ; cunt < strlen(buffer) ; cunt++)
    {
        if (buffer[cunt] == '\n')string_counter++;
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

int scanf_new_string (Onegin* lines, int* nomer_stroki_v_Onegine, int* nomer_elementa_v_buffere, char* buffer, size_t buffer_size) //Не забыть передать 0 в начале !
{
    int tmp_string_len = 0;
    char tmp_symbol = buffer[*nomer_elementa_v_buffere];
    while (tmp_symbol != '\0' )
    {

        tmp_string_len += 1;
        //printf ("%d %c || ", *nomer_elementa_v_buffere, tmp_symbol);
        *nomer_elementa_v_buffere += 1;
        tmp_symbol = buffer[*nomer_elementa_v_buffere];

    }

    if (tmp_string_len == 0){
        *nomer_elementa_v_buffere += 1;
        return STRING_END;}

    lines[*nomer_stroki_v_Onegine].stringg = &buffer[*nomer_elementa_v_buffere - tmp_string_len];
    lines[*nomer_stroki_v_Onegine].str_lengh = tmp_string_len;
    *nomer_elementa_v_buffere += 1;
    *nomer_stroki_v_Onegine += 1;

    if (*nomer_elementa_v_buffere >= buffer_size)
            return END_OF_FILE;

    return CORRECT;
}

int scanf_all_strings (Onegin* lines, int* nomer_stroki_v_Onegine, int* nomer_elementa_v_buffere, char* buffer, size_t buffer_size)
{
    int correct_check = DEFAULT;
    while (correct_check != END_OF_FILE)
    {

        correct_check = scanf_new_string (lines, nomer_stroki_v_Onegine, nomer_elementa_v_buffere, buffer, buffer_size);

    }
}

int printf_all_strings (Onegin* lines, int* nomer_stroki_v_Onegine)
{
    for (int neformal = 0 ; neformal < *nomer_stroki_v_Onegine ; neformal++)
    {
        printf ("%s\n", lines[neformal].stringg);
    }
    printf ("-------------------------------------------------------------------\n");
}

int compare_two_strings (Onegin* firstString, Onegin* secondString)
{
    size_t first = firstString->str_lengh;
    size_t second = secondString->str_lengh;
    for (int char_pos = 0 ; char_pos < std::min(first, second) ; char_pos++)
    {
        if (fix_capital_letter( firstString->stringg[char_pos] ) > fix_capital_letter( secondString->stringg[char_pos]) ) return FIRST_IS_BIGGER;
        if (fix_capital_letter( firstString->stringg[char_pos] ) < fix_capital_letter( secondString->stringg[char_pos]) ) return SECOND_IS_BIGGER;
    }

    if (first > second)
        return FIRST_IS_BIGGER;

    else if (first <= second)
        return SECOND_IS_BIGGER;
}

int compare_two_strings_reverse (char* firstString, char* secondString)
{
    size_t first = strlen(firstString) - 1;
    size_t second = strlen(secondString) - 1;
    for (int char_pos = 0 ; char_pos < std::min(first, second) ; char_pos++)
    {
        if (fix_capital_letter( firstString[first - char_pos] ) > fix_capital_letter( secondString[second - char_pos]) ) return FIRST_IS_BIGGER;
        if (fix_capital_letter( firstString[first - char_pos] ) < fix_capital_letter( secondString[second - char_pos]) ) return SECOND_IS_BIGGER;
        if (first > second)
            return FIRST_IS_BIGGER;
        else
            return SECOND_IS_BIGGER;
    }

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
    int result = compare_two_strings_reverse ( ((Onegin*)str1)->stringg, ((Onegin*)str2)->stringg);
    if (result == FIRST_IS_BIGGER)  return 1;
    if (result == SECOND_IS_BIGGER) return -1;
    else                            return 0;

}

void sort_strings_alphabet (Onegin* stroka, int* nomer_stroki)
{   /*
    char* tmp_buffer = stroka[0].stringg;
    int tmp_counter = NULL;
    int lengh = NULL;
    for (int i = 0 ; i < *nomer_stroki; i++)
    {
        for (int j = 0 + i ; j < *nomer_stroki; j++)
        {
            if (compare_two_strings (stroka[j].stringg, tmp_buffer) == SECOND_IS_BIGGER)
            {
                tmp_buffer = stroka[j].stringg;
                tmp_counter = j;
            }
        }
        //printf("%s", tmp_buffer);
        stroka[tmp_counter].stringg = stroka[i].stringg;
        stroka[i].stringg = tmp_buffer;
        tmp_buffer = stroka[i+1].stringg;
        lengh = stroka[tmp_counter].str_lengh;
        stroka[tmp_counter].str_lengh = stroka[i].str_lengh;
        stroka[i].str_lengh= lengh;


        }
        */
        qsort (stroka, *nomer_stroki, sizeof(Onegin), comporator);




}

void sort_strings_alphabet_reverse (Onegin* stroka, int* nomer_stroki)
{
    /*
    char* tmp_buffer = stroka[0].stringg;
    int tmp_counter = NULL;
    int lengh = NULL;
    for (int i = 0 ; i < *nomer_stroki; i++)
    {
        for (int j = 0 + i ; j < *nomer_stroki; j++)
        {
            if (compare_two_strings_reverse (stroka[j].stringg, tmp_buffer) == SECOND_IS_BIGGER)
            {
                tmp_buffer = stroka[j].stringg;
                tmp_counter = j;
            }
        }
        //printf("%s", tmp_buffer);
        stroka[tmp_counter].stringg = stroka[i].stringg;
        stroka[i].stringg = tmp_buffer;
        tmp_buffer = stroka[i+1].stringg;
        lengh = stroka[tmp_counter].str_lengh;
        stroka[tmp_counter].str_lengh = stroka[i].str_lengh;
        stroka[i].str_lengh= lengh;

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

void printf_first_variant (int* nomer_elementa_v_buffere, char* buffer, size_t buffer_size)
{
    *nomer_elementa_v_buffere = 0;
    int correct_check = DEFAULT;
    while (correct_check != END_OF_FILE)
    {

        correct_check = printf_first_varinat_string (nomer_elementa_v_buffere, buffer, buffer_size);

    }
}

int printf_first_varinat_string (int* nomer_elementa_v_buffere, char* buffer, size_t buffer_size) //Не забыть передать 0 в начале !
{
    int tmp_string_len = 0;
    char tmp_symbol = buffer[*nomer_elementa_v_buffere];
    while (tmp_symbol != '\0' )
    {

        tmp_string_len += 1;
        *nomer_elementa_v_buffere += 1;
        tmp_symbol = buffer[*nomer_elementa_v_buffere];

    }

    if (tmp_string_len == 0){
        *nomer_elementa_v_buffere += 1;
        return STRING_END;}

    printf("%s\n", &buffer[*nomer_elementa_v_buffere - tmp_string_len]);

    *nomer_elementa_v_buffere += 1;

    if (*nomer_elementa_v_buffere >= buffer_size)
            return END_OF_FILE;

    return CORRECT;
}
