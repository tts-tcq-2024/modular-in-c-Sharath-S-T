#include "color_pair.h"

const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
            MajorColorNames[colorPair->majorColor],
            MinorColorNames[colorPair->minorColor]);
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

// New feature: Prints the color code reference manual
void PrintColorCodeManual() {
    printf("Color Code Manual:\n");
    for (int i = 1; i <= numberOfMajorColors * numberOfMinorColors; i++) {
        ColorPair colorPair = GetColorFromPairNumber(i);
        char colorPairName[16];
        ColorPairToString(&colorPair, colorPairName);
        printf("%d -> %s\n", i, colorPairName);
    }
}

