#include "color_pair.h"
#include <stdlib.h>  // For malloc

const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

// Check if the pair number is valid
int isValidPairNumber(int pairNumber) {
    int totalPairs = numberOfMajorColors * numberOfMinorColors;
    return pairNumber >= 1 && pairNumber <= totalPairs;
}

// Check if the major color is valid
int isValidMajorColor(int majorColor) {
    return majorColor >= 0 && majorColor < numberOfMajorColors;
}

// Check if the minor color is valid
int isValidMinorColor(int minorColor) {
    return minorColor >= 0 && minorColor < numberOfMinorColors;
}

char* ColorPairToString(const ColorPair* colorPair) {
    char* buffer = (char*)malloc(16 * sizeof(char));  // Allocate memory
    sprintf(buffer, "%s %s", MajorColorNames[colorPair->majorColor], MinorColorNames[colorPair->minorColor]);
    return buffer;  // Return the string buffer
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

void appendColorPairToManual(char* manual, int pairNumber) {
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    if (colorPair.majorColor != -1 && colorPair.minorColor != -1) {
        char* colorPairName = ColorPairToString(&colorPair);
        char line[32];
        sprintf(line, "%d -> %s\n", pairNumber, colorPairName);
        strcat(manual, line);  // Append the line to the manual
        free(colorPairName);  // Free the allocated memory
    }
}

char* GenerateColorCodeManual() {
    int totalPairs = numberOfMajorColors * numberOfMinorColors;
    char* manual = (char*)malloc(totalPairs * 24 * sizeof(char));  // Allocate enough space
    manual[0] = '\0';  // Start with an empty string

    for (int i = 1; i <= totalPairs; i++) {
        appendColorPairToManual(manual, i);
    }
    return manual;  // Return the full manual as a string
}
