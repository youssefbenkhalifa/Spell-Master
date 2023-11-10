#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "Easy.c"    

int n;
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
    char name1[20];
    char name2[20];
    printf("Player one, please enter name: ");
    scanf("%s",name1);
    if(b=='b'){
        strcpy(name2,"bot");
    }else{
        printf("Player two, please enter name: ");
        scanf("%s",name2);
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
 
    char p1input[20], p2input[20]=" ";
    int i = 1;
    srand(time(0));
    int random = rand() % 2  + 1;
    char temp[20];
    if(random==2){
        strcpy(temp,name1);
        strcpy(name1,name2);
        strcpy(name2,temp);
    }    
    while (true){

        
        if(strcmp(name1,"bot")==0){
            strcpy(p1input,easy(p2input[strlen(p2input)-1],spells,usedSoFar));
            printf("Bot chose : %s \n ",p1input);
        }else{
            printf("%s, go!:",name1);
            scanf("%s", &p1input);
        }
        if (contains(spells, p1input) == 0)
        {
            printf("The spell is not in the provided list! \n%s wins!",name2);
            break;
        }
        if (i != 1)
        {
            if (p1input[strlen(p1input) - 1] == p2input[0])
            {
                printf("The spell\'s first character must match the last character of the previously chosen spell.\n %s wins!",name2);
                break;
            }
        }
        if (contains(usedSoFar, p1input) == 1)
        {
            printf("The spell has already been used!\n%s wins!",name2);
            break;
        }
        char l = p1input[strlen(p1input)-1];
        if(outofwords(spells,l,usedSoFar)){
            printf("no more spells in the list that satisfy the character matching condition, %s wins!\n",name1);
            break;
        }
        strcpy(usedSoFar[i], p1input);
        i++;
        strcpy(temp,name1);
        strcpy(name1,name2);
        strcpy(name2,temp);
        strcpy(p2input,p1input);


    }
    return 0;
}
