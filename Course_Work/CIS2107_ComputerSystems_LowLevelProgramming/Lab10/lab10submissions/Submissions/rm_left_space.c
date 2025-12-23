#include <stdio.h>

#include "myStrings.h"

void rm_left_space(char *s) {
    char *temp = s;

    while (*temp==' ' || *temp=='\t' || *temp == '\n' || *temp == '\r' || *temp == '\f' || *temp == '\v') {
        temp++;
    }

    int count = 0;

    while (*temp != '\0') {
        s[count] = *temp;
        count++;
        temp++;
    }

    s[count] = '\0';


}