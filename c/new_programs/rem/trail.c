#include <stdio.h>
#include <string.h>

// Define s and d globally so they can be accessed in main and other functions
char s[100], d[100];

// Function prototypes
void cb_input(void (*fp)(char [], char []));
void str_cpy(char d[], char s[]);
void cb_output(void (*fp)(char [], char []));

void cb_input(void (*fp)(char [], char []))
{
    printf("Enter string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Remove the newline character if present
    fp(d, s); // Call the function pointer with d and s
}

void str_cpy(char d[], char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        d[i] = s[i];
    d[i] = '\0';
}

void cb_output(void (*fp)(char [], char []))
{
    printf("s: %s\n", s);
    printf("d: %s\n", d);
}

int main()
{
    void (*fp)(char [], char []) = str_cpy;

    cb_input(fp); // Pass function pointer to cb_input
    cb_output(fp); // Pass function pointer to cb_output

    return 0;
}

