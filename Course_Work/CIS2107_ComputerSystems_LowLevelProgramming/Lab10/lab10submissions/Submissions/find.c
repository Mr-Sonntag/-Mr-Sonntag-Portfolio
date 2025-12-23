#include "myStrings.h"

int find(char *h, char *n) {
    int index = -1;

    for (int i = 0; h[i] != '\0'; i++) {
        if (h[i] == n[0]) {
            char *temp = n;
            int j = i;
            while (*temp == h[j] && *temp != '\0') {
                temp++;
                j++;
            }
            if (*temp == '\0') {
                index = i;
                return index;
            }
        }
    }

    return index;
}