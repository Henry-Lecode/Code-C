#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    char name[10];
    char id[5];
    float gpa;
};

typedef struct Student Student;

void inputStudent(Student *a, int e);
void outputStudent(Student *a, int e);
void menu();
void sortWithList(Student *a, int e);
int sortName(const void *ptr1, const void *ptr2);
int sortId(const void *ptr1, const void *ptr2);
int sortGpa(const void *ptr1, const void *ptr2);
void searchName(Student *a, int e);
void searchId(Student *a, int e);
void searchGpa(Student *a, int e);
void updateInfo(Student *a, int e);
void menu1();
void updateName(Student *a, int e);
void updateId(Student *a, int e);
void updateGpa(Student *a, int e);

void inputStudent(Student *a, int e) {
    for (int i = 0; i < e; i++) {
        printf("\nInput info student #%d.\n", i + 1);
        printf("Input name.\n");
        scanf("%9[^\n]%*c", a[i].name);
        printf("Input ID.\n");
        scanf("%9[^\n]%*c", a[i].id);
        printf("Input GPA.\n");
        scanf("%f", &a[i].gpa);
        getchar();
    }
}

void outputStudent(Student *a, int e) {
    printf("|#...|NAME      |ID        |GPA  |\n");
    for (int i = 0; i < e; i++) {
        printf("|%-4d|%-10s|%-10s|%5.1f|\n", i + 1, a[i].name, a[i].id, a[i].gpa);
    }
}

void menu() {
    printf("Please choose tool !\n"
           "(1) Sorting name go up\n"
           "(2) Sorting ID go up\n"
           "(3) Sorting GPA go up\n"
           "(4) Search name\n"
           "(5) Search ID\n"
           "(6) Search GPA\n"
           "(7) Quit\n");
}

int sortName(const void *ptr1, const void *ptr2) {
    Student *x = (Student*)ptr1;
    Student *y = (Student*)ptr2;
    if (strcmp(x->name, y->name) < 0) {
        return -1;
    }
    if (strcmp(x->name, y->name) > 0) {
        return 1;
    }
    return 0;
}

int sortId(const void *ptr1, const void *ptr2) {
    Student *x = (Student*)ptr1;
    Student *y = (Student*)ptr2;
    if (strcmp(x->id, y->id) < 0) {
        return -1;
    }
    if (strcmp(x->id, y->id) > 0) {
        return 1;
    }
    return 0;
}

int sortGpa(const void *ptr1, const void *ptr2) {
    Student *x = (Student*)ptr1;
    Student *y = (Student*)ptr2;
    if (x->gpa < y->gpa) {
        return -1;
    }
    if (x->gpa > y->gpa) {
        return 1;
    }
    return 0;
}

void searchName(Student *a, int e) {
    char N[10];
    printf("Input name to find.\n");
    scanf("%9[^\n]%*c", N);
    for (int i = 0; i < e; i++) {
        if (strcmp(a[i].name, N) == 0) {
            printf("FOUND !\n");
            printf("|%-10s|%-10s|%5.1f|\n", a[i].name, a[i].id, a[i].gpa);
        }
    }
}

void searchId(Student *a, int e) {
    char I[10];
    printf("Input ID to find.\n");
    scanf("%9[^\n]%*c", I);
    for (int i = 0; i < e; i++) {
        if (strcmp(a[i].id, I) == 0) {
            printf("FOUND !\n");
            printf("|%-10s|%-10s|%5.1f|\n", a[i].name, a[i].id, a[i].gpa);
        }
    }
}

void searchGpa(Student *a, int e) {
    float G;
    printf("Input GPA to find.\n");
    scanf("%f", &G);
    for (int i = 0; i < e; i++) {
        if (a[i].gpa == G) {
            printf("FOUND !\n");
            printf("|%-10s|%-10s|%5.1f|\n", a[i].name, a[i].id, a[i].gpa);
        }
    }
}

void sortWithList(Student *a, int e) {
    int c;
    menu();
    scanf("%d", &c);
    getchar();
    while (c != 7) {
        switch (c) {
            case 1:
                qsort(a, e, sizeof(Student), sortName);
                outputStudent(a, e);
                printf("\n--------------------\n");
                break;
            case 2:
                qsort(a, e, sizeof(Student), sortId);
                outputStudent(a, e);
                printf("\n--------------------\n");
                break;
            case 3:
                qsort(a, e, sizeof(Student), sortGpa);
                outputStudent(a, e);
                printf("\n--------------------\n");
                break;
            case 4:
                searchName(a, e);
                printf("\n--------------------\n");
                break;
            case 5:
                searchId(a, e);
                printf("\n--------------------\n");
                break;
            case 6:
                searchGpa(a, e);
                printf("\n--------------------\n");
                break;
            default:
                printf("Please choose ONE tool again !\n");
        }
        menu();
        scanf("%d", &c);
        getchar();
    }
    printf("\nThank you for your using service !\n\n");
}

void menu1() {
    printf("Choose kind of updating.\n"
           "(1) Updating name\n"
           "(2) Updating ID\n"
           "(3) Updating GPA\n"
           "(4) Quit\n");
}

void updateName(Student *a, int e) {
    char N[10], NN[10];
    printf("Input old name.\n");
    scanf("%9[^\n]%*c", N);
    printf("Input new name.\n");
    scanf("%9[^\n]%*c", NN);
    for (int i = 0; i < e; i++) {
        if (strcmp(a[i].name, N) == 0) {
            strcpy(a[i].name, NN);
            printf("|%-10s|%-10s|%5.1f|\n", a[i].name, a[i].id, a[i].gpa);
        }
    }
}

void updateId(Student *a, int e) {
    char I[10], II[10];
    printf("Input old ID.\n");
    scanf("%9[^\n]%*c", I);
    printf("Input new ID.\n");
    scanf("%9[^\n]%*c", II);
    for (int i = 0; i < e; i++) {
        if (strcmp(a[i].id, I) == 0) {
            strcpy(a[i].id, II);
            printf("|%-10s|%-10s|%5.1f|\n", a[i].name, a[i].id, a[i].gpa);
        }
    }
}

void updateGpa(Student *a, int e) {
    float G, GG;
    printf("Input old GPA.\n");
    scanf("%f", &G);
    printf("Input new GPA.\n");
    scanf("%f", &GG);
    for (int i = 0; i < e; i++) {
        if (a[i].gpa == G) {
            a[i].gpa = GG;
            printf("|%-10s|%-10s|%5.1f|\n", a[i].name, a[i].id, a[i].gpa);
        }
    }
}

void updateInfo(Student *a, int e) {
    int c;
    menu1();
    scanf("%d", &c);
    getchar();
    while (c != 4) {
        switch (c) {
            case 1:
                updateName(a, e);
                printf("\n--------------------\n");
                break;
            case 2:
                updateId(a, e);
                printf("\n--------------------\n");
                break;
            case 3:
                updateGpa(a, e);
                printf("\n--------------------\n");
                break;
            default:
                printf("Please choose ONE kind !\n");
        }
        menu1();
        scanf("%d", &c);
        getchar();
    }
    printf("\nThank you for your using service !\n\n");
}

int main(void) {
    int e;
    printf("Input amount of student.\n");
    scanf("%d", &e);
    getchar();
    Student a[e];

    inputStudent(a, e);
    printf("\n--------------------\n");
    outputStudent(a, e);
    printf("\n--------------------\n");
    sortWithList(a, e);
    printf("\n--------------------\n");
    updateInfo(a, e);
    printf("\n--------------------\n");

    return 0;
}
