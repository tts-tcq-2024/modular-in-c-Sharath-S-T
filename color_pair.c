#include "color_pair.h"
#include <stdlib.h>  // For malloc

const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

char* ColorPairToString(const ColorPair* colorPair) {
    char* buffer = (char*)malloc(16 * sizeof(char));  // Allocate memory
    sprintf(buffer, "%s %s", MajorColorNames[colorPair->majorColor], MinorColorNames[colorPair->minorColor]);
    return buffer;  // Return the string buffer
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor = (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors + colorPair->minorColor + 1;
}

char* GenerateColorCodeManual() {
    int totalPairs = numberOfMajorColors * numberOfMinorColors;
    char* manual = (char*)malloc(totalPairs * 24 * sizeof(char));  // Allocate enough space for all pairs
    manual[0] = '\0';  // Start with an empty string

    // Use loop without adding complexity through conditionals
    for (int i = 1; i <= totalPairs; i++) {
        ColorPair colorPair = GetColorFromPairNumber(i);
        char* colorPairName = ColorPairToString(&colorPair);
        char line[32];
        sprintf(line, "%d -> %s\n", i, colorPairName);
        strcat(manual, line);  // Append the line to the manual
        free(colorPairName);  // Free the allocated memory for color pair name
    }
    return manual;  // Return the full manual as a string
}
