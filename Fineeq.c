// The competition BOT
// The array needs to have NULL as a last element since the size is not known
// The strategy
/*
if the previous spell is an empty string the bot returns the word hin which the last letter is the least likely to be a first letter() with the least occurence as a first letter)
otherwise it returns a word that starts with the last letter from previous and that has as a last letter, the letter that occurs the least as the first letter.

*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int occu(char letter, char **spells) {
    int count = 0;
    int n = 0;

    for (int i = 0; spells[i] != NULL; i++) {
        n++;
    }

    for (int i = 0; i < n; i++) {
        size_t length = strlen(spells[i]);
        char firstChar = spells[i][0];
        if (firstChar == letter) {
            count++;
        }
    }
    return count;
}

char *castSpell_MRYD(char **spells, char *previous) {
    int n = 0;
    for (int i = 0; spells[i] != NULL; i++) {
        n++;
    }
    // to check if it's not empty
    char letter = (strlen(previous) > 0) ? previous[strlen(previous) - 1] : '\0';
    char valid[n][50];
    int j = -1;

    for (int i = 0; i < n; i++) {
        if (spells[i][0] == letter) {
            j++;
            strcpy(valid[j], spells[i]);
        }
    }

    char l;
    int occ[n];

    if (strcmp(previous, "") == 0) {
        for (int i = 0; i < n; i++) {
            l = spells[i][strlen(spells[i]) - 1];
            occ[i] = occu(l, spells);
            if (occ[i] == 0) {
                // we won
                return strdup(spells[i]);
            }
        }

        int min = 0;
        for (int i = 1; i < n; i++) {
            if (occ[i] < occ[min]) {
                min = i;
            }
        }

        return strdup(spells[min]);
    } else if (j == -1) {
        // we lost, no words match the requirements
        return strdup(spells[0]);
    } else {
        for (int i = 0; i <= j; i++) {
            l = valid[i][strlen(valid[i]) - 1];
            if (occu(l, spells) == 0) {
                return strdup(valid[i]);
            }
        }

        int min = 0;
        for (int i = 1; i <= j; i++) {
            if (occu(valid[i][strlen(valid[i]) - 1], spells) < occu(valid[min][strlen(valid[min]) - 1], spells)) {
                min = i;
            }
        }

        return strdup(valid[min]);
    }
}

int main() {
    char *array[] = {"wora", "aog", "dmps", "dxam", "project", "dandom", "array", "apple", "game", "rocket", NULL};
    printf("word: %s\n", castSpell_MRYD(array, ""));
    return 0;
}
