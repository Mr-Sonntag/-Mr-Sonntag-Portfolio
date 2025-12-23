#include "myStrings.h"

int diff(char *s1, char *s2) {
    char *temp = s1;
    int s1_len = 0;
    int s2_len = 0;
    int difference = 0;

    while (*temp != '\0') {
        s1_len++;
        temp++;
    }
    temp = s2;

    while (*temp != '\0') {
        s2_len++;
        temp++;
    }

    if (s1_len <= s2_len) {
        difference = s2_len - s1_len;

        while (*s1 != '\0') {
            if (*s1 != *s2) {
                difference++;
            }
            s1++;
            s2++;
        }
    }else {
        difference = s1_len - s2_len;

        while (*s2 != '\0') {
            if (*s1 != *s2) {
                difference--;
            }
            s2++;
            s1++;
        }
    }

    return difference;
}