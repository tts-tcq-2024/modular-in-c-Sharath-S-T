#include "color_manual.h"
#include "color_pair.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* ColorPairToString(const ColorPair* colorPair) {
    char* buffer = (char*)malloc(16 * sizeof(char));  // Allocate memory
    sprintf(buffer, "%s %s", MajorColorNames[colorPair->majorColor], MinorColorNames[colorPair->minorColor]);
    return buffer;  // Return the string buffer
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

void PrintColorCodeManual() {
    char* manual = GenerateColorCodeManual();
    printf("%s", manual);
    free(manual);  // Free the allocated memory for the manual
}
