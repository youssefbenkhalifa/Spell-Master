#ifndef FUNCTIONS_H
#define FUNCTIONS_H

bool contains(char array[][20], char string[]);
bool outofwords(char array[][20], char c,char usedSoFar[][20]);
int occurrencesFirst(char letter, char spells[][20], char usedSpells[][20]);
int occurrencesLast(char letter, char spells[][20], char usedSpells[][20]);


#endif