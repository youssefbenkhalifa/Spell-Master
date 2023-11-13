#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>  
#include "functions.c"
#include "functions.h"
#include <assert.h>
int n=3;
// Run this code to validate the methods used
void test_contains() {
    char array[3][50] = {"word", "table", "cmps"};
    assert(contains(array, "random") == false);
    assert(contains(array, "cmps") == true);
}

void test_outofwords() {
    char array[3][50] = {"word", "table", "cmps"};
    char usedSoFar[2][50] = {"word", "table"};
    assert(outofwords(array, 't', usedSoFar) == true);
    assert(outofwords(array, 'c', usedSoFar) == false);
}

void test_occurrencesNotUsed() {
    char spells[3][50] = {"word", "table", "cmps"};
    char usedSpells[2][50] = {"word", "table"};
    assert(occurrencesNotUsed('c', spells, usedSpells) == 1);
    assert(occurrencesNotUsed('t', spells, usedSpells) == 0);
}

void test_occu() {
    char spells[3][50] = {"word", "table", "cmps"};
    assert(occu('f', spells) == 0);
    assert(occu('t', spells) == 1);
}

int main() {
    test_contains();
    test_outofwords();
    test_occurrencesNotUsed();
    test_occu();
    printf("All test cases passed!\n");

    return 0;
}
