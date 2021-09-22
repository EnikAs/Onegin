#include "functions.h"

int main()
{
    FILE* file_stream = fopen ("text1.txt", "r"); // ��������� ��������� ������ ����� ����� ���� ������ �����
    //freopen("textout.txt", "w", stdout);
    if (file_stream == NULL)
    {
        printf("ETO NE SHAKESPEARE (i ne Onegin))))))");
        return 0;
    }

    int correct_check = DEFAULT;
    size_t buffer_size = scanf_file_size(file_stream);
    char* buffer = (char*) calloc(buffer_size + 1, sizeof(char));
    if (buffer == NULL)   //wrapper
    {
        printf ("POLNOE GOVNO, BUFFERA NET!!!!!!!!");
        return 0;
    }

    int string_counter = scanf_buffer(file_stream, buffer, &buffer_size);
    Onegin* lines = (Onegin*) calloc(string_counter, sizeof(Onegin));

    int nomer_stroki_v_Onegine = 0;
    int nomer_elementa_v_buffere = 0;

    correct_check = scanf_all_strings (lines, &nomer_stroki_v_Onegine, &nomer_elementa_v_buffere, buffer, buffer_size);

    sort_strings_alphabet (lines, &nomer_stroki_v_Onegine);
    printf_all_strings (lines, &nomer_stroki_v_Onegine);

    sort_strings_alphabet_reverse (lines, &nomer_stroki_v_Onegine);
    printf_all_strings (lines, &nomer_stroki_v_Onegine);

    printf_first_variant (&nomer_elementa_v_buffere, buffer, buffer_size);

    fclose(file_stream);

    free (buffer);
    free (lines);

    return 0;
}
