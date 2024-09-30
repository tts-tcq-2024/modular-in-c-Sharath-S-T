#ifndef COLOR_TESTS_H
#define COLOR_TESTS_H

#include "color_pair.h"

void testPairNumberToColorPair(int pairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor);
void testColorPairToPairNumber(enum MajorColor major, enum MinorColor minor, int expectedPairNumber);
void runTests();

#endif // COLOR_TESTS_H
