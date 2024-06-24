#include <stdio.h>
#include <time.h>
#include <unistd.h> 

int main() {
    while (1) {
        time_t current_time;
        struct tm * time_info;
        char timeString[9]; // HH:MM:SS + '\0'

        time(&current_time);
        time_info = localtime(&current_time);

        strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
        printf("Current time: %s\n", timeString);

        sleep(10);
    }

    return 0;
}

