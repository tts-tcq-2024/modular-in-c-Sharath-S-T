#include "color_pair.h"
#include <stdlib.h>
#include <stdio.h>

const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

const int INVALID_MAJOR_COLOR = -1;
const int INVALID_MINOR_COLOR = -1;

int isValidMajorColor(int majorColor) {
    return majorColor >= 0 && majorColor < numberOfMajorColors;
}

int isValidMinorColor(int minorColor) {
    return minorColor >= 0 && minorColor < numberOfMinorColors;
}

int ValidatePairNumber(int pairNumber) {
    return (pairNumber >= 1 && pairNumber <= (numberOfMajorColors * numberOfMinorColors)) ? 1 : -1;
}

int ValidateColorPair(const ColorPair* colorPair) {
    if (colorPair == NULL) return -1;
    if (isValidMajorColor(colorPair->majorColor) && isValidMinorColor(colorPair->minorColor)) {
        return 1;
    }
    return -1;
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair = { INVALID_MAJOR_COLOR, INVALID_MINOR_COLOR };
    if (ValidatePairNumber(pairNumber) == -1) {
        return colorPair; // Invalid pair
    }
    
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor = (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    if (ValidateColorPair(colorPair) == -1) {
        return -1;  // Error code for invalid color
    }
    return colorPair->majorColor * numberOfMinorColors + colorPair->minorColor + 1;
}
