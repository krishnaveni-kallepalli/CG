#include <stdio.h>
#include <stdbool.h>

volatile int i = 23;

void modify_i() {
    i = 42;
}

int main() {
    char ch = getchar();

    if (ch == 'a') {
        int x = 10;
        while (x != 0) {
            i++;
            x--;
            if (x == 5) {
                modify_i(); 
            }
        }
    }

    printf("%d\n", i);

    return 0;
}

