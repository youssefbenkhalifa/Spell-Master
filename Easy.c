#include <stdio.h>
#include <string.h>
int search(char *item, char **array){
    int n = sizeof(array);
    for (int i = 0; i < n; i++){
        if(strcmp(array[i],item)){
            return 1;
        }
     }
     return 0;
}
char* easyMode(char letter, char* spells[], char* UsedSoFar[], int numWords, int numUsedWords) {
    for (int i = 0; i < numWords; i++) {
        if (spells[i][0] == letter) {
            int used = 0;
            for (int j = 0; j < numUsedWords; j++) {
                if (strcmp(spells[i], UsedSoFar[j]) == 0) {
                    used = 1;
                    break;
                }
            }
            if (!used) {
                return spells[i];
            }
        }
    }
    return NULL; // If no word is found
}