#include "myStrings.h"

void rm_space(char *s) {
    char *temp = s;
    int count = 0;
    while (*temp != '\0') {
        temp++;
        count++;
    }
    temp--;
    count--;
    if (*temp==' ' || *temp=='\t' || *temp == '\n' || *temp == '\r' || *temp == '\f' || *temp == '\v') {
        while (*temp==' ' || *temp=='\t' || *temp == '\n' || *temp == '\r' || *temp == '\f' || *temp == '\v') {
            temp--;
            count--;
        }
    }

    s[count+1] = '\0';

    temp = s;

    while (*temp==' ' || *temp=='\t' || *temp == '\n' || *temp == '\r' || *temp == '\f' || *temp == '\v') {
        temp++;
    }

    count = 0;

    while (*temp != '\0') {
        s[count] = *temp;
        count++;
        temp++;
    }

    s[count] = '\0';
}