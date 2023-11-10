#include <stdio.h>
#include <stdbool.h>
#include <string.h>
extern int n;

bool contains(char array[n][20], char string[])
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
bool outofwords(char array[n][20], char c,char usedSoFar[n][20])
{
    for (int i = 0; i < n; i++)
    {
        if (c == array[i][0] && contains(usedSoFar,array[i])==false)
        { 
            return false;
        }
    }
    return true;
}
int Occurrences(char letter, char spells[n][20], char usedSpells[n][20]){
    int count=0;
     for (int i = 0; i < n; i++) {
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