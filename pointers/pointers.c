#include <stdio.h>
#include <stdbool.h>

int string_length(char *s)
{
    int length = 0;

    while (*s != '\0')
    {
        length++;
        s = s + 1;
    }
    return length;
}
/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    int length = string_length(y);
    for (int i = 0; i <= length; i++)
    {
        x[i] = y[i];
    }
    // x[length] = '\0';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    int length = string_length(str);
    for (int i = 0; i < length; i++)
    {
        int char_num = str[i];
        if (char_num == c)
        {
            return str + i;
        }
    }
    return NULL;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    int needle_length = string_length(needle);
    int haystack_length = string_length(haystack);

    for (int i = 0; i <= haystack_length - needle_length; i++)
    {
        if (haystack[i] == needle[0])
        {
            bool isMatch = true;
            for (int j = 1; j < needle_length; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    isMatch = false;
                }
            }
            if (isMatch)
            {
                return haystack + i;
            }
        }
    }
    return NULL;
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
