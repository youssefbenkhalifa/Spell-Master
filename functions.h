#ifndef FUNCTIONS_H
#define FUNCTIONS_H

bool contains(char array[][50], char string[]);
bool outofwords(char array[][50], char c,char usedSoFar[][50]);
int occurrencesNotUsed(char letter, char spells[][50], char usedSpells[][50]);
int occu(char letter, char spells[][50]);


#endif