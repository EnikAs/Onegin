#ifndef FUNCTION_LIB
#define FUNCTION_LIB

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum for_correct_check
{
    STRING_END,
    END_OF_FILE,
    CORRECT,
    INCORRECT,
    DEFAULT
};

enum compare_something
{
    FIRST_IS_BIGGER,
    SECOND_IS_BIGGER,
    EQUAL
};

enum for_tmp_string
{
    TMP_STRING_START,
    TMP_STRING_MIDDLE
};

struct Onegin
{
    char* stringg;
    size_t str_lengh;
};

const int MAX_STRING_SIZE = 1000000;

size_t      scanf_file_size                 (FILE* file_stream);

void        scanf_buffer                    (FILE* file_stream, char* buffer, size_t* buffer_size);

void        sort_strings_alphabet           (Onegin* stroka, int* nomer_stroki_v_Onegine);

void        sort_strings_alphabet_reverse   (Onegin* stroka, int* nomer_stroki_v_Onegine);

void        printf_first_variant            (int* nomer_elementa_v_buffere, char* buffer, size_t buffer_size);

void        buffer_optimise                 (char* buffer, size_t buffer_size);

int         compare_two_strings             (Onegin* firstString, Onegin* secondString);

int         compare_two_strings_reverse     (char* firstString, char* secondString);

int         cunt_strings                    (char* buffer);

int         fix_capital_letter              (int c);

int         printf_first_varinat_string     (int* nomer_elementa_v_buffere, char* buffer, size_t buffer_size);

int         scanf_all_strings               (Onegin* lines, int* nomer_stroki_v_Onegine, int* nomer_elementa_v_bufere, char* buffer, size_t buffer_size);

int         printf_all_strings              (Onegin* lines, int* nomer_stroki_v_Onegine);

int         scanf_new_string                (Onegin* lines, int* nomer_stroki_v_Onegine, int* nomer_elementa_v_bufere, char* buffer, size_t buffer_size);

int         comporator                      (const void* str1, const void* str2);

int         comporator_reverse              (const void* str1, const void* str2);


#endif
