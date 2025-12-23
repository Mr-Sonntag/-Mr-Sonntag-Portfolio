#include <ctype.h>

#include "myStrings.h"

int strcmp_ign_case(char *s1, char *s2) {
    char *temp = s1;
    int s1Len = 0;
    int s2Len = 0;

    while (*temp != '\0') {
        s1Len++;
        temp++;
    }

    temp = s2;
    while (*temp != '\0') {
        s2Len++;
        temp++;
    }

    if (s1Len >= s2Len) {
        while (*s2 != '\0') {
            if (tolower(*s2) > tolower(*s1)) {
                return 1;
            }else if (tolower(*s2) < tolower(*s1)) {
                return -1;
            }
            s2++;
            s1++;
        }
        return 0;
    }else {
        while (*s1 != '\0') {
            if (tolower(*s2) > tolower(*s1)) {
                return 1;
            }else if (tolower(*s2) < tolower(*s1)) {
                return -1;
            }
            s2++;
            s1++;
        }
        return 0;
    }
}