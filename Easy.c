#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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
 
void OccursFirstEasy(char letter, char spells[78][20], char usedSpells[78][20]){
    for( int i = 0 ; i < 78 ; i++){
       if ( spells[i][0]==letter && contains(usedSpells,spells[i])==0 ){
           printf("%s!", spells[i]);
         //need to add the spell to the usedSpells array
         //strcopy(usedSpell[],spells[i]);
           return;
       }
    }
     printf("i lost!");
     return ;
}

int main() {
  char spells[78][20] = {
        "accio", "obliviate", "liberacorpus", "scourgify", "protego"};

    char usedSpells[78][20] = {"accio"};
    
    OccursFirstEasy('s', spells, usedSpells);
   
    return 0;
}
