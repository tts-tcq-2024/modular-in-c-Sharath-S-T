#include "color_pair.h"
#include "color_tests.h"

int main() {
    runTests();
    
    // Generate and print the color code manual
    char* manual = GenerateColorCodeManual();
    printf("%s", manual);
    free(manual);  // Free the allocated memory for the manual

    return 0;
}
