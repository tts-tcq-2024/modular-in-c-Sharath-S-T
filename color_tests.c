#include "color_pair.h"
#include "color_tests.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void testNumberToPair(int pairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor) {
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char* colorPairNames = ColorPairToString(&colorPair);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
    free(colorPairNames);  // Free the allocated memory
}

void testPairToNumber(enum MajorColor major, enum MinorColor minor, int expectedPairNumber) {
    ColorPair colorPair = {major, minor};
    int pairNumber = GetPairNumberFromColor(&colorPair);
    assert(pairNumber == expectedPairNumber);
}

void testColorCodeManual() {
    char* manual = GenerateColorCodeManual();
    assert(strstr(manual, "1 -> White Blue") != NULL);
    assert(strstr(manual, "25 -> Violet Slate") != NULL);
    free(manual);  // Free the allocated memory for the manual
}

void runTests() {
    testNumberToPair(1, WHITE, BLUE);
    testNumberToPair(5, WHITE, SLATE);
    testNumberToPair(6, RED, BLUE);
    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
    testColorCodeManual();
}
