#include <stdio.h>
#include <stdlib.h>

#include "myStrings.h"

void take_last(char *s, int n) {

    char *temp = s;
    int s1Len = 0;

    while (*temp != '\0') {
        s1Len++;
        temp++;
    }

    if (s1Len<n) return;

    int j = s1Len-n;
    for (int i = 0; i < n; i++) {
        s[i] = s[j];
        j++;
    }
    s[n] = '\0';
}