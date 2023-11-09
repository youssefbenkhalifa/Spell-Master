
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "driver.c"
bool contains(char array[10][20], char string[])
{
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(array[i], string) == 0)
        { // strcmp compares two strings, returns 0 if they're equal, 1/-1 otherwise.
            return true;
        }
    }
    return false;
}
 
void easy(char letter, char spells[n][20], char usedSpells[n][20], int storeUsed) {
    for( int i = 0 ; i < 78 ; i++){
       if ( spells[i][0]==letter && contains(usedSpells,spells[i])==0 ){
           printf("%s!", spells[i]);
           strcpy(usedSpells[storeUsed],spells[i]);
           return;
       }
    }
     printf("i lost!");
     return ;
}

int main() {
  char spells[n][20] = {
        "accio", "obliviate", "liberacorpus", "scourgify", "protego"};

    char usedSpells[78][20] = {"accio"};
    int i=1;
    easy('s', spells, usedSpells, i);
   
    return 0;
}
