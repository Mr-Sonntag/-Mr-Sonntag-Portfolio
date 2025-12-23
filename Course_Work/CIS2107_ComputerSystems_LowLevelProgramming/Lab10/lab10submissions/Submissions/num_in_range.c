#include <ctype.h>

#include "myStrings.h"

int num_in_range(char *s1, char b, char t) {
    int count = 0;
    while (*s1 != '\0') {
        if (tolower(*s1) >= tolower(b) && tolower(*s1) <= tolower(t)) {
            count++;
        }
        s1++;
    }
    return count;
}