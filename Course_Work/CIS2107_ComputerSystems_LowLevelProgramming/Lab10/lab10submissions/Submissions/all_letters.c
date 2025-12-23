#include "myStrings.h"

int all_letters(char *s) {
    int letters = 0;

    while (*s!= '\0') {
        if ((int)*s <= 57 && (int)*s >= 48) {
            return letters;
        }
        s++;
    }
    letters = 1;

    return letters;

}