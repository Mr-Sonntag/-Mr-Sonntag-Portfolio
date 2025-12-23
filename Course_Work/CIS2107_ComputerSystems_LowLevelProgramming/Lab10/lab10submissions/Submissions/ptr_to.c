#include <stddef.h>

#include "myStrings.h"

char *ptr_to(char *h, char *n) {
    char *indexPtr = NULL;

    for (int i = 0; h[i] != '\0'; i++) {
        if (h[i] == n[0]) {
            char *temp = n;
            int j = i;
            while (*temp == h[j] && *temp != '\0') {
                temp++;
                j++;
            }
            if (*temp == '\0') {
                indexPtr = &h[i];
                return indexPtr;
            }
        }
    }

    return indexPtr;
}