#include <stdio.h>
#include <string.h>

void count(char s[], int len) {
    int i, count = 0;

    for (i = 0; i <= len; i++) {
        if (s[i] != ' ' && s[i] != '\0') {
            count++;
        } else {
            if (count > 0) {
                printf("%d ", count);
                count = 0;
            }
        }
    }
    printf("\n");
}

int main() {
    char s[100];
    int len;

    printf("Enter string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Remove newline character from fgets input

    len = strlen(s); // Calculate the length of the string

    count(s, len);

    return 0;
}

