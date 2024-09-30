#include "color_manual.h"
#include "color_pair.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* ColorPairToString(const ColorPair* colorPair) {
    char* buffer = (char*)malloc(16 * sizeof(char));
    sprintf(buffer, "%s %s", MajorColorNames[colorPair->majorColor], MinorColorNames[colorPair->minorColor]);
    return buffer;
}

void appendColorPairToManual(char* manual, int pairNumber) {
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    if (colorPair.majorColor != INVALID_MAJOR_COLOR && colorPair.minorColor != INVALID_MINOR_COLOR) {
        char* colorPairName = ColorPairToString(&colorPair);
        char line[32];
        sprintf(line, "%d -> %s\n", pairNumber, colorPairName);
        strcat(manual, line);
        free(colorPairName);
    }
}

char* GenerateColorCodeManual() {
    int totalPairs = numberOfMajorColors * numberOfMinorColors;
    char* manual = (char*)malloc(totalPairs * 24 * sizeof(char));
    manual[0] = '\0';

    for (int i = 1; i <= totalPairs; i++) {
        appendColorPairToManual(manual, i);
    }
    return manual;
}

void PrintColorCodeManual() {
    char* manual = GenerateColorCodeManual();
    // printf("%s", manual);
    free(manual);
}
