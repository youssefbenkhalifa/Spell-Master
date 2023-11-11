#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "easyMode.c"    
#include "hardMode.c"    
#include "mediumMode.c"    
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
    printf("Press b the enter to play against a bot \npress any button then enter to play against an other player: \n");
    char b;
    scanf("%c",&b);
    char currentPlayer[20];
    char otherPlayer[20];
    printf("Player one, please enter name: ");
    scanf("%s",currentPlayer);
    int mode ;
    if(b=='b'){
        strcpy(otherPlayer,"bot");
        printf("Press 1 for Easy Mode \nPress 2 for Medium Mode \nPress 3 for Hard Mode:\n");
        scanf("%d",&mode);
        
    }else{
        printf("Player two, please enter name: ");
        scanf("%s",otherPlayer);
    }
    
    // Printing the words
    for(int i = 1; i <= n; i++) {
        printf("%-20s", spells[i]);
        // to print in a table-like format
        if ((i ) % 5 == 0 || i == n ) {
            printf("\n");
        }
    }
    printf("\n");
    char current[20], previous[20]="";
    int i = 0;
    srand(time(0));
    int random = rand() % 2  + 1;
    char temp[20];
    if(random==2){
        strcpy(temp,currentPlayer);
        strcpy(currentPlayer,otherPlayer);
        strcpy(otherPlayer,temp);
    }
    if(mode==1){
        printf("--------------------- EASY MODE ---------------------\n");
    }else if(mode==2){
        printf("--------------------- MEDIUM MODE ---------------------\n");
    }else{
        printf("--------------------- HARD MODE ---------------------\n");
    }
    while (true){        
        if(strcmp(currentPlayer,"bot")==0){
            if (mode==1){
                easyMode(previous,spells,usedSoFar,current);
            } else if (mode==2){
                mediumMode(previous,spells,usedSoFar,current);
            }else if (mode==3){
                hardMode(previous,spells,usedSoFar,current);
            }else{
                printf("Invalid Mode Input please try again..");
                return 1;
            }
            hardMode(previous,spells,usedSoFar,current);
            printf("Bot chose : %s \n",current);
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
