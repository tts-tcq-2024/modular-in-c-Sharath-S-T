#include "color_pair.h"
#include <stdlib.h>  // For malloc
#include <stdio.h>

const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

int isValidPairNumber(int pairNumber) {
    int totalPairs = numberOfMajorColors * numberOfMinorColors;
    return pairNumber >= 1 && pairNumber <= totalPairs;
}

int isValidMajorColor(int majorColor) {
    return majorColor >= 0 && majorColor < numberOfMajorColors;
}

int isValidMinorColor(int minorColor) {
    return minorColor >= 0 && minorColor < numberOfMinorColors;
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair = { -1, -1 };  // Initialize with invalid values
    if (!isValidPairNumber(pairNumber)) {
        printf("Invalid Pair Number: %d\n", pairNumber);
        return colorPair;  // Return invalid pair
    }
    
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor = (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    if (!isValidMajorColor(colorPair->majorColor)) {
        printf("Invalid Major Color: %d\n", colorPair->majorColor);
        return -1;  // Error code for invalid color
    }
    if (!isValidMinorColor(colorPair->minorColor)) {
        printf("Invalid Minor Color: %d\n", colorPair->minorColor);
        return -1;  // Error code for invalid color
    }
    
    return colorPair->majorColor * numberOfMinorColors + colorPair->minorColor + 1;
}
