#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "functions.h"
extern int n;

char* hardMode(char letter, char spells[n][20], char usedSpells[n][20]) {
    char notUsed[n][20];
    int occ[n];
    int j=-1;
    for(int i=0;i<n;i++){
        if(contains(usedSpells,spells[i])==false && spells[i][0]==letter){
            j++;
            strcpy(notUsed[j],spells[i]);
        }
    }
    for(int i=0;i<j;i++){
        occ[i] = occurrencesFirst(notUsed[i][strlen(notUsed[i])-1],spells,usedSpells);
        if(occ[i]==0){
            // That's a direct win
            return notUsed[i];
        }
    }
/*
    int j=0;

    for(int l=0;l<j;l++){
        char notUsedTemp[n][20];
        char current[20] =notUsed[j];
        int occ[n];    
        for(int i=0;i<n;i++){
        if(contains(usedSpells,notUsed[i])==false && notUsed[i][0]==current[strlen(current)-1]){
            strcpy(notUsedTemp[l],notUsed[i]);
        }
    }
        occ[i] = occurrencesLast(notUsed[i][strlen(notUsed[i])-1],spells,usedSpells);
        if(occ[i]==0){
            // That's a direct win
            return notUsed[i];
        }
    }



*/    
}
