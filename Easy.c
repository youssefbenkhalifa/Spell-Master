#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>  
#include "functions.h"

extern int n;

char* easy(char letter, char spells[n][20], char usedSpells[n][20]) {
    for( int i = 1 ; i < n ; i++){
       if ( spells[i][0]==letter && contains(usedSpells,spells[i])==0){
          // printf("%s!", spells[i]);
           return spells[i];
       }
    }
     //printf("i lost!");
     return spells[1];
}


