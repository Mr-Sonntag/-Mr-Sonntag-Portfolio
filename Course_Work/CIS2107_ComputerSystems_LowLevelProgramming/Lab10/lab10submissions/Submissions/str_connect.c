#include <stddef.h>
#include <stdlib.h>

#include "myStrings.h"

char *str_connect(char **strs, int n, char c) {
    // int size = 0;

    // char **aPtr =strs;
    char **temp = strs;
    int length = 0;
    int totallen = 0;
    while (*temp != NULL) {
        length++;
        temp++;
    }

    if (n > length) return NULL;

    temp = strs;
    for (int i = 0; i < n; i++) {
        char *temp1 = *temp;
        while (*temp1 != '\0') {
            totallen++;
            temp1++;
        }
        temp++;
    }

    char *result = malloc((totallen+n));

    temp = strs;
    int index = 0;
    for (int i = 0; i < n; i++) {
        char *temp1 = *temp;
        while (*temp1 != '\0') {
            result[index] = *temp1;
            temp1++;
            index++;
        }
        result[index++] = c;
        temp++;
    }

    result[totallen+n-1] = '\0';

    return result;
}