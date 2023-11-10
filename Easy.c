#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
extern int n;
bool contain(char array[n][20], char string[])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(array[i], string) == 0)
        { // strcmp compares two strings, returns 0 if they're equal, 1/-1 otherwise.
            return true;
        }
    }
    return false;
}
char* easy(char letter, char spells[n][20], char usedSpells[n][20]) {
    for( int i = 1 ; i < n ; i++){
       if ( spells[i][0]==letter && contain(usedSpells,spells[i])==0){
          // printf("%s!", spells[i]);
           return spells[i];
       }
    }
     //printf("i lost!");
     return spells[1];
}


