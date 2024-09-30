#ifndef COLOR_PAIR_H
#define COLOR_PAIR_H

#include <stdio.h>
#include <string.h>

enum MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET, INVALID_MAJOR_COLOR = -1 };
enum MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE, INVALID_MINOR_COLOR = -1 };

extern const char* MajorColorNames[];
extern const char* MinorColorNames[];
extern const int numberOfMajorColors;
extern const int numberOfMinorColors;

typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;

char* ColorPairToString(const ColorPair* colorPair);
ColorPair GetColorFromPairNumber(int pairNumber);
int GetPairNumberFromColor(const ColorPair* colorPair);
int ValidatePairNumber(int pairNumber);
int ValidateColorPair(const ColorPair* colorPair);

#endif // COLOR_PAIR_H
