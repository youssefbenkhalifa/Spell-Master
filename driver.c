#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
    
=======

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
bool sameLetter(char str1[], char str2[])
{
    if (str1[strlen(str1) - 1] == str2[0])
    {
        return true;
    }
    return false;
}
int main()
{
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
    for(int i = 0; i < n; i++) {
        printf("%-20s", spells[i]);
        // to print in a table
        if ((i + 1) % 5 == 0 || i == n - 1) {
            printf("\n");
        }
    }
 

    char usedSpells[n][20] = {"x"}; // initializes an array of strings.

    char p1input[20], p2input[20];
    int i = 1;

    while (true)
    {
        printf("Player 1, go!:");
        scanf("%s", &p1input);

        if (contains(spells, p1input) == 0)
        {
            printf("The spell is not in the provided list! \nPlayer 2 wins!");
            break;
        }
        if (i != 1)
        {
            if (sameLetter(p2input, p1input) == 0)
            {
                printf("The spell\'s first character must match the last character of the previously chosen spell.\n Player 2 wins!");
                break;
            }
        }
        if (contains(usedSpells, p1input) == 1)
        {
            printf("The spell has already been used!\nPlayer 2 wins!");
            break;
        }
        strcpy(usedSpells[i], p1input);
        i++;

        printf("Player 2, go!:");
        scanf("%s", &p2input);

        if (contains(spells, p2input) == 0)
        {
            printf("The spell is not in the provided list! \nPlayer 1 wins!");
            break;
        }
        if (sameLetter(p1input, p2input) == 0)
        {
            printf("The spell\'s first character must match the last character of the previously chosen spell.\n Player 1 wins!");
            break;
        }
        if (contains(usedSpells, p2input) == 1)
        {
            printf("The spell has already been used! \nPlayer 1 wins!");
            break;
        }
        strcpy(usedSpells[i], p2input);
        i++;
>>>>>>> cc9da1fdefc2decb4721194cf5ca01f2c76d2b81
    }

    return 0;
}
