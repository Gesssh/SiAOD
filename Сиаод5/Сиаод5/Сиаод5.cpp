////18. Написать программу, которая реализует метод открытого хеширования и хеш - функцией,основанной на методе умножения.
////Данные, хранящиеся в файле занести в хеш - таблицу.Файл должен содержать не менее 15 целых чисел.
////Вывести построенную хеш - таблицу на экран(вместе с количеством выполненных проб).
////Организовать поиск данных в хеш - таблице.Результаты поиска данных вывести на экран.
////Также вывести количество проб, которые были затрачены при поиске.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int data;
    struct Table* next;
}Table;

int prob = 0;
int GetHash(int, int);
void Add(Table**, int, int);
void Search(Table**, int, int);
void Output(Table**, int);
void FMemory(Table**, int);

int main() {
    int n, i, value;
    printf("mod = "); scanf("%d", &n);
    Table* M[n];

    for (i = 0; i < n; i++) {
        M[i] = NULL;
    }

    FILE* In = fopen("Input.txt", "r");

    while (!feof(In)) {
        fscanf(In, "%d", &value);
        Add(M, n, value);
    }

    fclose(In);
    Output(M, n);
    printf("\n\nSearch key: "); scanf("%d", &value);

    Search(M, n, value);
    FMemory(M, n);

    return 0;

}

double GetHash(double n, double value) {
    int k;
    float a = 0.618033;
    float e;//n=2,
    double  t = 1;
    //float value=1;
    k = (n * modf(value * a, &t)) / 1;
    return value;
}

void Add(Table** M, int n, int value) {

    int hash = GetHash(n, value);

    if (M[hash] == NULL) {
        if (!(M[hash] = (Table*)malloc(sizeof(Table)))) {
            printf("Ошибка выделения памяти");
            exit(2);
        }

        M[hash]->data = value;
        M[hash]->next = NULL;

    }
    else {
        Table* tmp = M[hash], * add;
        if (!(add = (Table*)malloc(sizeof(Table)))) {
            printf("Ошибка выделения памяти");
            exit(3);
        }

        add->data = value;
        add->next = NULL;

        while (tmp->next != NULL) {
            tmp = tmp->next;
            prob++;

        }

        tmp->next = add;
        prob++;

    }

}

void Search(Table** M, int n, int value) {
    int hash = GetHash(n, value), count = 0;
    Table* tmp = M[hash];

    while ((tmp != NULL) && (tmp->data != value)) {
        tmp = tmp->next;
        count++;
    }

    if (tmp != NULL) {
        printf("Key found");
    }
    else {
        printf("Key not found");
    }
    printf("\nProb: %d", count);
}

void Output(Table** M, int n) {
    int i;
    Table* tmp;

    for (i = 0; i < n; i++) {
        tmp = M[i];
        if (tmp != NULL) {
            printf("\n");
            while (tmp != NULL) {
                printf("%d ", tmp->data);
                tmp = tmp->next;
            }
        }
    }
    printf("\nProb: %d", prob);
}

void FMemory(Table** M, int n) {
    int i;
    Table* tmp;
    for (i = 0; i < n; i++) {
        tmp = M[i];
        while (tmp != NULL) {
            tmp = M[i]->next;
            free(M[i]);
            M[i] = tmp;
        }
    }
}

