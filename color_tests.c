#include "color_pair.h"
#include "color_tests.h"
#include <assert.h>
#include <stdio.h>

void testNumberToPair(int pairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor) {
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[16];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s for pair number %d\n", colorPairNames, pairNumber);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(enum MajorColor major, enum MinorColor minor, int expectedPairNumber) {
    ColorPair colorPair = {major, minor};
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d for pair %s %s\n", pairNumber,
           MajorColorNames[major], MinorColorNames[minor]);
    assert(pairNumber == expectedPairNumber);
}

void runTests() {
    testNumberToPair(1, WHITE, BLUE);   // 1 -> White Blue
    testNumberToPair(2, WHITE, ORANGE); // 2 -> White Orange
    testNumberToPair(3, WHITE, GREEN);  // 3 -> White Green
    testNumberToPair(4, WHITE, BROWN);   // 4 -> White Brown
    testNumberToPair(5, WHITE, SLATE);   // 5 -> White Slate
    testNumberToPair(6, RED, BLUE);      // 6 -> Red Blue
    testPairToNumber(BLACK, ORANGE, 12); // Black Orange -> 12
    testPairToNumber(VIOLET, SLATE, 25);  // Violet Slate -> 25
}
