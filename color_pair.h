#ifndef COLOR_PAIR_H
#define COLOR_PAIR_H

#include <stdio.h>
#include <string.h>

enum MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET, INVALID_MAJOR_COLOR = -1 };
enum MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE, INVALID_MINOR_COLOR = -1 };

const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;

extern const char* MajorColorNames[];
extern const char* MinorColorNames[];
extern int numberOfMajorColors;
extern int numberOfMinorColors;

char* ColorPairToString(const ColorPair* colorPair);
ColorPair GetColorFromPairNumber(int pairNumber);
int GetPairNumberFromColor(const ColorPair* colorPair);
int ValidatePairNumber(int pairNumber);
int ValidateColorPair(const ColorPair* colorPair);

#endif // COLOR_PAIR_H
