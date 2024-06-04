#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h> // Include for wait() function

struct res
{
    char a[10];
    char b[10];
};

int main()
{
    pid_t p1, p2;
    struct res *r;
    r = (struct res *)malloc(sizeof(struct res));

    strcpy(r->a, "hello");
    strcpy(r->b, "hie");

    // Create two child processes
    p1 = fork();
    if (p1 == 0)
    {
        // Child process 1 (p1) using resource 'a'
        printf("Process 1 is using resource A: %s\n", r->a);
        // Add your code for process 1 here
        // ...

        // Wait for resource 'b' to be released by p2
        printf("Process 1 waiting for resource B to be released...\n");
        while (strcmp(r->b, "available") != 0)
            sleep(1); // Sleep for 1 second

        printf("Process 1 acquired resource B.\n");
        // Continue with process 1 logic
        // ...
        exit(0);
    }
    else
    {
        // Parent process
        p2 = fork();
        if (p2 == 0)
        {
            // Child process 2 (p2) using resource 'b'
            printf("Process 2 is using resource B: %s\n", r->b);
            // Add your code for process 2 here
            // ...

            // Wait for resource 'a' to be released by p1
            printf("Process 2 waiting for resource A to be released...\n");
            while (strcmp(r->a, "available") != 0)
                sleep(1); // Sleep for 1 second

            printf("Process 2 acquired resource A.\n");
            // Continue with process 2 logic
            // ...
            exit(0);
        }
        else
        {
            // Parent process waiting for both children to finish
            wait(NULL);
            wait(NULL);
            printf("Both processes have completed.\n");
        }
    }

    free(r); // Free allocated memory
    return 0;
}

