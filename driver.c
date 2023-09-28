#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    FILE * Fptr;
    Fptr = fopen("spells.txt","r");
    char line[20];    
    fgets(line,20,Fptr);
    int n = atoi(line);
    printf("We have %d spells \n",n);
    int count = -1;
    char spells[n][20];
    // putting all spells in an array for easier access
    if(Fptr!=NULL){
        while(fgets(line,20,Fptr)){
            count++;
            int j=0;
            for(int i=0;i<strlen(line);i++){
                if(line[i]!='\n'){
                    line[j] = line[i];
                    j++;
                }
            }
            line[j] = '\0';
            strcpy(spells[count],line);
        }
    }
    fclose(Fptr);
    for (int i = 0; i < n; i++) {
        printf("%-20s", spells[i]);
        // to print in a table
        if ((i + 1) % 5 == 0 || i == n - 1) {
            printf("\n");
        }
    }

    return 0;
}