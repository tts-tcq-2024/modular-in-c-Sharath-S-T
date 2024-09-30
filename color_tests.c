#include "color_tests.h"
#include "color_manual.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testPairNumberToColorPair(int pairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor) {
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testColorPairToPairNumber(enum MajorColor major, enum MinorColor minor, int expectedPairNumber) {
    ColorPair colorPair = {major, minor};
    int pairNumber = GetPairNumberFromColor(&colorPair);
    assert(pairNumber == expectedPairNumber);
}

void testColorCodeManual() {
    char* manual = GenerateColorCodeManual();
    assert(strstr(manual, "1 -> White Blue") != NULL);
    assert(strstr(manual, "25 -> Violet Slate") != NULL);
    free(manual);
}

void testInvalidPairNumber(int pairNumber) {
    int result = ValidatePairNumber(pairNumber);
    assert(result == -1);
}

void testInvalidColorPair(const ColorPair* colorPair) {
    int result = ValidateColorPair(colorPair);
    assert(result == -1);
}

void runTests() {
    // Valid cases
    testPairNumberToColorPair(1, WHITE, BLUE);
    testPairNumberToColorPair(5, WHITE, SLATE);
    testPairNumberToColorPair(6, RED, BLUE);
    testColorPairToPairNumber(BLACK, ORANGE, 12);
    testColorPairToPairNumber(VIOLET, SLATE, 25);
    testColorCodeManual();

    // Invalid cases
    testInvalidPairNumber(100);  // Out of bounds
    testInvalidPairNumber(0);     // Below valid range

    ColorPair invalidColorPair = {5, 0}; // Invalid major color
    testInvalidColorPair(&invalidColorPair);
    
    invalidColorPair = (ColorPair){0, 5}; // Invalid minor color
    testInvalidColorPair(&invalidColorPair);

    invalidColorPair = (ColorPair){5, 5}; // Both invalid
    testInvalidColorPair(&invalidColorPair);
}
