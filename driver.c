#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "easyMode.c"    
#include "functions.h"
#include "functions.c"

int n;



int main()
{
    // reading file and displaying spells
    FILE * Fptr;
    Fptr = fopen("spells.txt","r");
    char line[20];    
    fgets(line,20,Fptr);
    n = atoi(line);
    printf("We have %d spells \n",n);
    int count = 0;
    char spells[n][20];
    char usedSoFar[n][20] ;
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
    // end of file reading
    printf("Press B to play against a bot, press enter to play against an other player: ");
    char b;
    scanf("%c",&b);
    char currentPlayer[20];
    char otherPlayer[20];
    printf("Player one, please enter name: ");
    scanf("%s",currentPlayer);
    if(b=='b'){
        strcpy(otherPlayer,"bot");
    }else{
        printf("Player two, please enter name: ");
        scanf("%s",otherPlayer);
    }
    
    // Printing the words
    printf("%s \n",spells[0]);
    for(int i = 0; i < n; i++) {
        printf("%-20s", spells[i]);
        // to print in a table-like format
        if ((i + 1) % 5 == 0 || i == n - 1) {
            printf("\n");
        }
    }
 
    char current[20]="$", previous[20]="!";
    int i = 0;
    srand(time(0));
    int random = rand() % 2  + 1;
    char temp[20];
    if(random==2){
        strcpy(temp,currentPlayer);
        strcpy(currentPlayer,otherPlayer);
        strcpy(otherPlayer,temp);
    }    
    while (true){

        
        if(strcmp(currentPlayer,"bot")==0){
            strcpy(current,easyMode(previous[strlen(previous)-1],spells,usedSoFar));
            printf("Bot chose : %s \n ",current);
        }else{
            printf("%s, go!:",currentPlayer);
            scanf("%s", &current);
        }
        if (contains(spells, current) == 0)
        {
            printf("The spell is not in the provided list! \n%s wins!",otherPlayer);
            break;
        }
        if (i != 0)
       {
            if (previous[strlen(previous) - 1] != current[0] )
            {
                printf("The spell\'s first character must match the last character of the previously chosen spell.\n %s wins!",otherPlayer);
                break;
            }
        }
        if (contains(usedSoFar, current) == 1)
        {
            printf("The spell has already been used!\n%s wins!",otherPlayer);
            break;
        }
        char l = current[strlen(current)-1];
        if(outofwords(spells,l,usedSoFar)){
            printf("no more spells in the list that satisfy the character matching condition, %s wins!\n",currentPlayer);
            break;
        }
        strcpy(usedSoFar[i], current);
        i++;
        strcpy(temp,currentPlayer);
        strcpy(currentPlayer,otherPlayer);
        strcpy(otherPlayer,temp);
        strcpy(previous,current);



    }
    return 0;
}
