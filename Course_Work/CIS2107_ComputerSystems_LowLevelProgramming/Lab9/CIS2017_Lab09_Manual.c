/*
 * Name:	Zachary Sonntag
 * Section:	03
 * Lab:  	CIS2107_Lab09_Manual
 * Goal: 	To design and implement functions taking pointers as arguments 
			to process characters and strings.
 */


#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions prototypes
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[]);
void endsWithed(char *string[]);

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f\n", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!\nhello";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    startsWithB(series);

    //test for endsWithed
    endsWithed(series);

}

// 1.(Displaying Strings in Uppercase and Lowercase) 
void * upperLower (const char * s) {
    puts("");
    char upper[100],lower[100];
    int i = 0;
    while (s[i]!='\0') {
        lower[i] = tolower(s[i]);
        upper[i] = toupper(s[i]);
        i++;
    }

    printf("%s, %s\n", lower, upper);
}

// 2.(Converting Strings to Integers for Calculations) 
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    int sum = atoi(s1) + atoi(s2) + atoi(s3) + atoi(s4);
    puts("");
    return sum;
}

//3.(Converting Strings to Floating Point for Calculations) 
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
   float sum = atof(s1) + atof(s2) + atof(s3) + atof(s4);
    puts("");

    return sum;

}

//4.(Comparing Strings) 
void compareStr(const char *s1, const char *s2) {

    puts("");
    int result = strcmp(s1, s2);
    if (result == 0) {
        printf("%s = %s", s1, s2);
    }else if (result>0) {
        printf("%s > %s", s1, s2);
    }else {
        printf("%s < %s", s1, s2);
    }

}

//5.(Comparing Portions of Strings) 
void comparePartialStr(const char *s1, const char *s2, int n) {
   int result = strncmp(s1, s2, n);
    puts("");
    if (result == 0) {
        printf("%s == %s", s1, s2);
    }else if (result>0) {
        printf("%s > %s", s1, s2);
    }else {
        printf("%s < %s", s1, s2);
    }

}

//6.(Random Sentences) 
void randomize(void) {

   char* article[] = {"The","A","One", "Some", "Any"};
   char* noun[] = {"boy", "girl", "dog", "town", "car"};
   char* verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
   char* preposition[] = {"to", "from", "over", "under", "on"};


   srand((unsigned) time(NULL));
   puts("");
   for (size_t i = 0; i < 20; i++) {
       char art[10];
       strncpy(art,article[rand() % 5], sizeof(art)-1);
       // strncpy(art, article[rand() % (RAND_MAX+1)+RAND_MAX]);

       art[0] = tolower((unsigned char)art[0]);

       printf("%s %s %s %s %s %s. ", article[rand() % 5], noun[rand() % 5], verb[rand() % 5], preposition[rand() % 5], art, noun[rand() % 5]);

   }
}

//7.(Tokenizing Telephone Numbers) 
int tokenizeTelNum(char *num) {
  const char delimeters[] = "- ()";
  char *token;
    char number[12];
    puts("");
    token = strtok(num, delimeters);
    while (token!=NULL) {
        strncat(number, token, sizeof(number)-1);
        strncat(number, " ", sizeof(number)-1);
        token = strtok(NULL, delimeters);
    }
    printf("Number: %s\n", number);
  
}

//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
    const char delimeters[] = " ";
    puts("");
    char *token;
    char reversed[50] = "";
    token = strtok(text, delimeters);
    while (token!=NULL) {
        char temp[10];
        strncat(temp, reversed, sizeof(temp)-1);
        strncpy(reversed, token, sizeof(reversed) - 1);
        strncat(reversed, " ", sizeof(reversed)-1);
        strncat(reversed, temp, sizeof(reversed)-1);
        token = strtok(NULL, delimeters);

    }

    printf("Reversed: %s\n", reversed);

}

//9.(Counting the Occurrences of a Substring) 
int countSubstr (char * line, char * sub) {
  int count = 0;

    puts("");
    while ((line = strstr(line, sub)) != NULL) {
        count++;
        line += strlen(sub);
    }
    return count;

  
}

//10.(Counting the Occurrences of a Character) 
int countChar (char *line, char c) {
  int count = 0;
    puts("");
    while ((line = strchr(line, c)) != NULL) {
        count++;
        line += 1;
    }
    return count;
  
}


//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
    char* alpha[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i = 0;
    puts("");
    while (string[i] != '\0') {
        string[i] = tolower(string[i]);
        i++;
    }

    for (size_t i = 0; i < 26; i++) {
        char *temp = string;
        while ((temp = strchr(temp, *alpha[i])) != NULL) {
            count[i]++;
            temp += 1;
        }
        printf("%c,%c | %d", toupper(*alpha[i]), *alpha[i], count[i]);
        puts("");
    }

 
 
}

//12.(Counting the Number of Words in a String) 
int countWords(char *string) {
   const char delimeters[] = " \n";

    puts("");
    char *token;
    int count = 0;
    token = strtok(string, delimeters);
    while (token!=NULL) {
        count++;
        token = strtok(NULL, delimeters);
    }
    return count;
}

//13.(Strings Starting with "b") 
void startsWithB(char *string[]) {
    puts("");
    while (*string!=NULL) {
        if (tolower(string[0][0]) == 'b') {
            printf("%s ", string[0]);
        }
        string++;
    }
    puts("Loop done");
 

}

//14.(Strings Ending with "ed") 
void endsWithed(char *string[]) {
    while (*string!=NULL) {
        size_t len = strlen(string[0]);

        int result = strcmp(string[0] + len - 2, "ed");
        if (result == 1) {
            printf("%s ", string[0]);
        }
        string++;
    }

}