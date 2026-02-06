/******************
 *   Guessing.c   *
 ******************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int lowerBound;
int upperBound;
int secretNumber;
int guess;
int count;

char* timestamp()
{
    struct tm* tp;
    time_t t;
    char* buffer = (char *) malloc(sizeof(char) * 9);
    time(&t);
    tp = localtime(&t);
    strftime(buffer, 9, "%H:%M:%S", tp);
    return buffer;
}

int main()
{
    char* timenow;
    printf("Geben Sie bitte die Untergrenze ein: ");
    scanf("%d", &lowerBound);
    printf("Geben Sie bitte die Obergrenze ein: ");
    scanf("%d", &upperBound);
    srand(time(NULL));
    secretNumber = (rand() % (upperBound - lowerBound + 1)) + lowerBound;
    timenow = timestamp();
    printf("\nEs wurde um %s eine Zufallszahl zwischen %d und %d erzeugt.\n",timenow, lowerBound, upperBound);
    printf("Deine Aufgabe ist es zu erraten, welche Zahl es ist.\n");
    printf("Viel Erfolg\n\n");
    free(timenow);
    count = 1;
    do
    {
        timenow = timestamp();
        printf("[%s]: Gib eine Zahl zwischen %d und %d ein: ", timenow, lowerBound, upperBound);
        scanf("%d", &guess);
        free(timenow);
        if(guess > secretNumber)
        {
            printf("Die gesuchte Zahl ist kleiner als Deine geratene Zahl.\n");
            count ++;
        }
        else if(guess < secretNumber)
        {
            printf("Die gesuchte Zahl ist größer als Deine geratene Zahl.\n");
            count ++;
        }
        else
        {
            printf("\nYeahh, das ist korrekt.\n");
            printf("Du hast %d Versuche benötigt.\n", count);
        }
    }
    while(guess != secretNumber);
}