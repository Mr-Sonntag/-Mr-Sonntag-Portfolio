#include <ctype.h>

#include "myStrings.h"

void capitalize(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i]>96 && s[i]<123) {
            if (i==0) {
                s[i] = toupper(s[i]);
            }else if (s[i-1]==32) {
                s[i] = toupper(s[i]);
            }
        }else {
            s[i] = tolower(s[i]);   
        }
    }
}