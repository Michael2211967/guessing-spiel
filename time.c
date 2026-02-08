#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* timestamp() {
    time_t rawtime;
    struct tm* timeinfo;
    char* buffer = (char*) malloc(sizeof(char) * 9); // Speicher für "HH:MM:SS\0"

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 9, "%H:%M:%S", timeinfo);

    return buffer;
}

int main() {
    char* currentTime = timestamp();
    printf("Aktuelle Zeit: %s\n", currentTime);
    free(currentTime); // Speicher freigeben, um Speicherlecks zu vermeiden
    return 0;
}