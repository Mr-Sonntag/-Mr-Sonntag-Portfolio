#include <stdio.h>
#include <stdlib.h>

#include "myStrings.h"

int len_diff(char *s1, char *s2) {
    int s1_len=0;
    int s2_len=0;
    char *s1_temp = s1;
    char *s2_temp = s2;

    while (*s1_temp != '\0') {
        s1_temp++;
        s1_len++;
    }

    while (*s2_temp != '\0') {
        s2_temp++;
        s2_len++;
    }

    return abs(s1_len - s2_len);
}