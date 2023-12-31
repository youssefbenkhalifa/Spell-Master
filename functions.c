#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int n;

bool contains(char array[n][50], char string[])
{
    for (int i = 1; i <=n; i++)
    {
        if (strcmp(array[i], string) == 0)
        { // strcmp compares two strings, returns 0 if they're equal, 1/-1 otherwise.
            return true;
        }
    }
    return false;
}
bool outofwords(char array[n][50], char c,char usedSoFar[n][50])
{
    for (int i = 1; i <= n; i++)
    {
        if (c == array[i][0] && contains(usedSoFar,array[i])==false)
        { 
            return false;
        }
    }
    return true;
}
int occurrencesNotUsed(char letter, char spells[n][50], char usedSpells[n][50]){
    int count=0;
     for (int i = 1; i <= n; i++) {
        if( !contains(usedSpells,spells[i])){
        size_t length = strlen(spells[i]);
        char firstChar = spells[i][0];
          if(firstChar==letter){
            count++;
          }
        }
    }
    return count;
}
int occu(char letter, char spells[n][50]){
    int count=0;
     for (int i = 1; i <= n; i++) {
        size_t length = strlen(spells[i]);
        char firstChar = spells[i][0];
          if(firstChar==letter){
            count++;
          }
        }
    return count;
}
