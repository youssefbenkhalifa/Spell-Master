#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "functions.h"
extern int n;

void mediumMode(char previous[] , char spells[n][20], char usedSpells[n][20],char next[20]) {
    int k = 0;
    for (int i=1;i<=n;i++){
        if(usedSpells[i]!=NULL){
            k++;
        }
    }
    char letter = previous[strlen(previous)-1];       
    char notUsed[n][20];
    int occ[n];
    int j=0;

    for(int i=1;i<n;i++){
        if(contains(usedSpells,spells[i])==false && spells[i][0]==letter){
            j++;
            strcpy(notUsed[j],spells[i]);
        }
    }
    if(strcmp(previous,"")==0 || j==0){
        srand(time(NULL)); // Seed the random number generator with the current time
        int randomIndex = rand() % (n - 1) ; 
        strcpy(next,spells[randomIndex]);
        return;
    }
       
        for(int i=1;i<j;i++){
            occ[i] = occurrencesNotUsed(notUsed[i][strlen(notUsed[i])-1],spells,usedSpells);
            if(occ[i]==0){
                // That's a direct win
                strcpy(next,notUsed[i]);
                return;
            }
        }
        int min = 1;
        for(int i=2;i<j;i++){
            if(occ[i]<occ[min]){
                min = i;
            }
        }
        strcpy(next,notUsed[min]);
        return;
            
  
}
