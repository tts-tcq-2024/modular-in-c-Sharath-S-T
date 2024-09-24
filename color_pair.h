#ifndef COLOR_PAIR_H
#define COLOR_PAIR_H

#include <stdio.h>

// Enum definitions
enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

// Color Pair structure
typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;

// Function prototypes
void ColorPairToString(const ColorPair* colorPair, char* buffer);
ColorPair GetColorFromPairNumber(int pairNumber);
int GetPairNumberFromColor(const ColorPair* colorPair);
void PrintColorCodeManual();

#endif
