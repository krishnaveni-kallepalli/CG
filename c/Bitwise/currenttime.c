#include <stdio.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h> 
#else
#include <unistd.h>
#endif

int main() 
{
    time_t t;
    struct tm *p;
    char input;
    while (1) {
		
	t = time(NULL);
	p = localtime(&t);
	printf("Current time: %02d:%02d:%02d\n", p->tm_hour, p->tm_min, p->tm_sec);

        #ifdef _WIN32
        Sleep(1000); 
        #else
        sleep(1);    
        #endif

       
        printf("Press 'q' to quit...\n");
        scanf(" %c", &input); 
        if (input == 'q' || input == 'Q') {
            break;  
        }
    }

    printf("Program terminated.\n");

    return 0;
}

