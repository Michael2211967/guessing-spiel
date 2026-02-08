/******************
 *   Guessing.c   *
 ******************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"mod/tools.h"

int main()
{
    int lowerBound;
    int upperBound;
    int secretNumber;
    int guess;
    int count;
    char* timenow;
    char prompt[80];

    lowerBound = getSafeInt("Geben Sie bitte die Untergrenze ein: ");
    upperBound = getSafeInt("Geben Sie bitte die Obergrenze ein: ");
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
        sprintf(prompt, "[%s]: Gib eine Zahl zwischen %d und %d ein: ", timenow, lowerBound, upperBound);
        guess = getSafeInt(prompt);
    
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