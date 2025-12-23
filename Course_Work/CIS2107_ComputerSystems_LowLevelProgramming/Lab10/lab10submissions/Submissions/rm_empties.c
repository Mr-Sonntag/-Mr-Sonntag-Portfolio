#include <stddef.h>
#include <stdlib.h>

#include "myStrings.h"

void rm_empties(char **words) {
    char **temp = words;
    int length = 0;

    while (*temp != NULL) {
        temp++;
        length++;
    }
    if (length < 1) return;

    int *indexs = calloc(length, sizeof(int));

    temp = words;

    for (int i = 0; i < length; i++) {
        char *empty = *temp;
        int size = 0;
        while (*empty != '\0' && size<1) {
            empty++;
            size++;
        }
        if (size>0) indexs[i]++;
        temp++;
    }

    for (int i = 0; i < length; i++) {
        if (indexs[i]==0) {
            int j = i;
            while (indexs[j]==0 && j<length) {
                j++;
            }

            if (j>=length) {
                words[i] = NULL;
                free(indexs);
                return;
            }
            words[i] = words[j];
            indexs[i] = 1;
            indexs[j] = 0;

        }
    }
}