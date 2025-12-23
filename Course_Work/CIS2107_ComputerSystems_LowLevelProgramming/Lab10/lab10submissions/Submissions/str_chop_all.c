#include <stddef.h>
#include <stdlib.h>

#include "myStrings.h"

char **str_chop_all(char *s, char c) {

    char *temp = s;
    int tokens = 1;

    while (*temp!='\0') {
        if (c == *temp) {
            tokens++;
        }
        temp++;
    }

    if (tokens == 1){
        char **result = malloc((tokens+1)* sizeof(char*));
        int length = 0;
        int index = 0;
        temp = s;
        while (*temp!='\0') {
            length++;
            temp++;
        }
        result[0] = malloc((length+1)*sizeof(char*));
        while (*s!='\0') {
            result[tokens][index] = *s;
            s++;
            index++;
        }
        result[0][length] = '\0';
        result[1]= NULL;
        return result;
    }

    char *temp2 = s;
    char **result = malloc((tokens + 1)*sizeof(char*));
    if (result == NULL) return NULL;
    temp = s;
    for (int i = 0; i < tokens; i++) {
        int index = 0;
        int length = 0;
        while (*temp!=c&&*temp!='\0') {
            length++;
            temp++;
        }
        result[i] = (char *) malloc((length + 1)* sizeof(char));
        if (result[i] == NULL) {
            free(result);
            result = NULL;
            return NULL;
        }
        while (*temp2 != c && *temp2 != '\0') {
            result[i][index] = *temp2;
            temp2++;
            index++;
        }
        result[i][index] = '\0';
        temp++;
        temp2++;

    }

    // result[tokens] = malloc(sizeof(char));
    result[tokens] = NULL;

    return result;
}