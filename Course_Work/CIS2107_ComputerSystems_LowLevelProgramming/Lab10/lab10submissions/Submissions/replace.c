#include <stddef.h>
#include <stdlib.h>

#include "myStrings.h"

char *replace(char *s, char *pat, char *rep) {
    char *temp = s;
    int slen = 0;
    int patlen = 0;
    int replen = 0;
    while (*temp != '\0') {
        temp++;
        slen++;
    }

    temp = pat;

    while (*temp != '\0') {
        temp++;
        patlen++;
    }

    temp = rep;
    while (*temp != '\0') {
        replen++;
        temp++;
    }

    int count = 0;

    temp = s;
    int tempindex = 0;
    int *index = calloc(slen, sizeof(int));
    while (*temp != '\0') {

        if (*temp == pat[0]) {
            int size = 1;
            for (int i = 1; temp[i] != '\0' || pat[i] != '\0'; i++) {
                if (temp[i] != pat[i]) {
                    break;
                }
                size++;
            }
            if (size == patlen) {
                count++;
                index[tempindex]++;
            }
        }
        temp++;
        tempindex++;
    }

    int totallen = slen - patlen*(count) + replen*(count);

    if (totallen<0) {
        free(index);
        return NULL;
    }


    char *result = malloc(totallen+1);



    for (int i = 0, j = 0; i < slen && j < totallen; i++,j++) {
        if (index[i] == 1) {
            temp = rep;
            while (*temp != '\0') {
                result[j] = *temp;
                temp++;
                j++;
            }
            i+= patlen-1;
            j--;
        }else {
            result[j] = s[i];
        }
    }

    result[totallen] = '\0';

    free(index);
    return result;

}
