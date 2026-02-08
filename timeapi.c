#include <windows.h>
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

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
    char* currentTime = timestamp();
    char timenow[25];
    sprintf(timenow, "Aktuelle Zeit: %s\n", currentTime);
    MessageBox(NULL, timenow, "Aktuelle Uhrzeit", MB_OK);
    free(currentTime); // Speicher freigeben, um Speicherlecks zu vermeiden
    return 0;
}