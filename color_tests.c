#include "color_pair.h"
#include "color_tests.h"
#include <assert.h>
#include <stdio.h>

void testNumberToPair(int pairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[16];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s for pair number %d\n", colorPairNames, pairNumber);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(enum MajorColor major, enum MinorColor minor, int expectedPairNumber)
{
    ColorPair colorPair = {major, minor};
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d for pair %s %s\n", pairNumber,
           MajorColorNames[major], MinorColorNames[minor]);
    assert(pairNumber == expectedPairNumber);
}

void runTests() {
    testNumberToPair(1, WHITE, BLUE);
    testNumberToPair(5, WHITE, SLATE);
    testNumberToPair(6, RED, BLUE);
    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
}
