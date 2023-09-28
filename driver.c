#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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
    char spells[78][20] = {
        "accio", "obliviate", "liberacorpus", "scourgify", "protego"};

    char usedSpells[78][20] = {"x"}; // initializes an array of strings.

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
    }

    return 0;
}
