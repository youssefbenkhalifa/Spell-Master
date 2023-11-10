#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool contains(char array[78][20], char string[])
{
    for (int i = 0; i < 78; i++)
    {
        if (strcmp(array[i], string) == 0)
        { // strcmp compares two strings, returns 0 if they're equal, 1/-1 otherwise.
            return true;
        }
    }
    return false;
}

int Occurrences(char letter, char spells[78][20], char usedSpells[78][20]){
    int count=0;
     for (int i = 0; i < 78; i++) {
        if( !contains(usedSpells,spells[i])){
        size_t length = strlen(spells[i]);
        char lastChar = spells[i][length - 1];
          if(lastChar==letter){
            count++;
          }
        }
    }
    return count;
}
int main() {
     char spells[78][20] = {
        "accio", "obliviate", "liberacorpus", "scourgify", "protego"};

    char usedSpells[78][20] = {"accio"};
    
    printf("%d", Occurrences('o',spells,usedSpells));
    
}
