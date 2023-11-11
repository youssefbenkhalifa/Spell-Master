#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>  
#include "functions.h"


extern int n;

void easyMode(char previous[], char spells[n][20], char usedSpells[n][20],char next[]) {
    char letter = previous[strlen(previous)-1];
    for( int i = 1 ; i < n ; i++){
       if ( spells[i][0]==letter && contains(usedSpells,spells[i])==0){
          // printf("%s!", spells[i]);
          strcpy(next,spells[i]);
           return ;
       }
    }
     //printf("i lost!");
    srand(time(NULL)); // Seed the random number generator with the current time
    int randomIndex = rand() % (n - 1) ; 
    strcpy(next,spells[randomIndex]);
    return ;
}


