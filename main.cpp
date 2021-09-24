#include "functions.h"

int main()
{
    FILE* file_stream = fopen ("text1.txt", "r"); // Аргументы командной строки чтобы можно было подать текст
    //freopen("textout.txt", "w", stdout);
    if (file_stream == NULL)
    {
        printf("File stream error!");
        return 0;
    }

    int correct_check = DEFAULT;
    size_t buffer_size = scanf_file_size(file_stream);
    char* buffer = (char*) calloc(buffer_size + 1, sizeof(char));
    if (buffer == NULL)   //wrapper
    {
        printf ("Buffer memory error!");
        return 0;
    }

    int string_counter = read_buffer(file_stream, buffer, &buffer_size);
    Onegin* lines = (Onegin*) calloc(string_counter, sizeof(Onegin));

    int string_number = 0;
    int buff_char_number = 0;

    correct_check = scanf_all_strings (lines, &string_number, &buff_char_number, buffer, buffer_size);

    sort_strings_alphabet (lines, &string_number);
    printf_all_strings (lines, &string_number);

    sort_strings_alphabet_reverse (lines, &string_number);
    printf_all_strings (lines, &string_number);

    printf_first_variant (&buff_char_number, buffer, buffer_size);

    fclose(file_stream);

    free (buffer);
    free (lines);

    return 0;
}
