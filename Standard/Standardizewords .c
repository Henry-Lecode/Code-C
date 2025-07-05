#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void input();
char* standard(char *s);
void standardizeWords(char *s);
void timeNow();
void storeTool(char *s);
void upperCase(char *s);
char* upper(char *s);

void timeNow() {
    time_t t;
    struct tm *timeTime;

    time(&t);
    timeTime = localtime(&t);

    printf("\nLast using: %02d/%02d/%04d - %02d:%02d:%02d\n",
           timeTime->tm_mday,
           timeTime->tm_mon + 1,
           timeTime->tm_year + 1900,
           timeTime->tm_hour,
           timeTime->tm_min,
           timeTime->tm_sec);
}

void input() {
    char s[100];
    printf("Input your name.\n");
    scanf("%99[^\n]%*c", s);
    storeTool(s);
}

void menu() {
    printf("\nPlease choose tool !\n");
    printf("(1) Standard words\n"
           "(2) Convert to uppercase\n"
           "(3) Quit\n");
}

void storeTool(char *s) {
    int c;
    char tmp1[100];
    char tmp2[100];
    strcpy(tmp1, s);
    strcpy(tmp2, s);
    menu();
    scanf("%d", &c);
    getchar();
    while (c != 3) {
        switch (c) {
            case 1:
                standardizeWords(tmp1);
                break;
            case 2:
                upperCase(tmp2);
                break;
            default:
                printf("Please choose ONE tool !\n");
        }
        menu();
        scanf("%d", &c);
        getchar();
    }
}

char* upper(char *s) {
    s[0] = toupper(s[0]);
    for (int i = 1; i < strlen(s); i++) {
        s[i] = toupper(s[i]);
    }
    return s;
}

void upperCase(char *s) {
    char ss[100] = "";
    char *token = strtok(s, " ");
    while (token != NULL) {
        strcat(ss, upper(token));
        token = strtok(NULL, " ");
        if (token != NULL) {
            strcat(ss, " ");
        }
    }
    printf("\nName after uppercase.\n");
    printf("%s\n", ss);
}

char* standard(char *s) {
    s[0] = toupper(s[0]);
    for (int i = 1; i < strlen(s); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

void standardizeWords(char *s) {
    char se[100] = "";
    char *token = strtok(s, " ");
    while (token != NULL) {
        strcat(se, standard(token));
        token = strtok(NULL, " ");
        if (token != NULL) {
            strcat(se, " ");
        }
    }
    printf("\nName after standard.\n");
    printf("%s\n", se);
}

int main(void) {
    input();
    timeNow();

    return 0;
}
