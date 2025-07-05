#include <stdio.h>
#include <time.h>

void chooseForm();
void timeNow();
void requestForChangeOfMajor();
void letterForFriend();
void informationOfStudent();

void menu() {
    printf("\n\n----------------------------------------------------------------------\n");
    printf("Choose form text you want !\n");
    printf("(1) Request for Change of Major\n"
           "(2) Letter for friend.\n"
           "(3) Information of student.\n"
           "(4) Quit\n");
}

void requestForChangeOfMajor() {
    FILE *f;

    f = fopen("DON1.txt", "w");
    fprintf(f, "\n\t\t\t\t\tSocialist Republic of Vietnam\n"
               "\t\t\t\t  Independence – Freedom – Happiness\n"
               "\t\t\t\t\t  REQUEST FOR CHANGE OF MAJOR\n\n"
               "\tTo:\n"
               "\tFull name:\n"
               "\tDay of bỉth:\n"
               "\tStudent ID:\n"
               "\tCurrent major\n"
               "\tProposed new major\n"
               "\tRequest details:\n"
               "\t..........\n"
               "\t..........\n"
               "\t..........\n"
               "\tI sincerely hope the Board of Rectors will kindly "
               "provide guidance\n\tand approve my request.\n"
               "\tRespectfully !\n"
               "\t\t\t\t\t\t\t\t\t\t....., ..../..../......\n"
               "\t\t\t\t\t\t\t\t\t\t\t\tSignature\n");
    fclose(f);

    f = fopen("DON1.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
    }
    fclose(f);
}

void letterForFriend() {
    FILE *f;

    f = fopen("DON1.txt", "w");
    fprintf(f, "\n\t[Your address]\n"
               "\t[Time writing]\n"
               "\tDear [Friend's name] !\n"
               "\t..........\n"
               "\t..........\n"
               "\t..........\n"
               "\tLet’s stay in touch more often. I really miss talking with you!\n"
               "\tTake care and write back soon.\n\n"
               "\tBest regards\n"
               "\t[Your name]\n");
    fclose(f);

    f = fopen("DON1.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
    }
    fclose(f);
}

void informationOfStudent() {
    FILE *f;

    f = fopen("DON1.txt", "w");
    fprintf(f, "\n\tFull name:\n"
               "\tDate of bỉth:\n"
               "\tGender: O Male, O Female.\n"
               "\tStudent ID:\n"
               "\tMajor:\n"
               "\tYear of study: 1st  2nd  3rd  4th\n"
               "\tPhone number:\n"
               "\tEmail:\n"
               "\tCurrent address:\n\n\n"
               "\t\t\t\t\t\t\t\t....., ..../..../......\n"
               "\t\t\t\t\t\t\t\t\t\tSignature\n");
    fclose(f);

    f = fopen("DON1.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
    }
    fclose(f);
}

void chooseForm() {
    int c;
    menu();
    scanf("%d", &c);
    getchar();
    while (c != 4) {
        switch (c){
            case 1:
                requestForChangeOfMajor();
                break;
            case 2:
                letterForFriend();
                break;
            case 3:
                informationOfStudent();
                break;
            default:
                printf("Please choose ONE form !\n");
        }
        menu();
        scanf("%d", &c);
        getchar();
    }
}

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

int main(void) {
    chooseForm();
    timeNow();

    return 0;
}
