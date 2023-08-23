/**
1. Используя стек, решить следующую задачу.
Текстовый файл Т, содержащий не менее пяти строк, состоит из слов,
разделенных пробелами и знаками препинания.
Вывести на экран каждое слово текстового файла в обратном порядке (с сохранением порядка слов в тексте).
Для реализации АТД Стек использовать динамическое распределение памяти.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

typedef struct StackNode
{
    int info;
    struct Stack *next;
}StackNode;
StackNode *Stack;

void init();
void Push(int);
int Pop();
bool IsEmpty();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FILE *F;
    F = fopen("F.txt","r");
    int flag=0,i;
    char H;

    while(fscanf(F,"%c",&H)!=eof(F))
    {
        if((H=='\n')||(H==' '))
        {
            for(i=flag;i>0;i--)
            {
                printf("%c",Pop());
            }
            flag=0;printf("%c",H);
        }
        else
        {
            flag++;
            Push(H);
        }
    }
    for(i=flag;i>0;i--)
    {
        printf("%c",Pop());
    }

    if(IsEmpty()==true) printf("\nСтекпустой\n");
    else printf("\nСтек не пустой\n");

    return 0;
}

void init()
{
Stack=NULL;
}

void Push(int pos)
{
    StackNode *p;
    p=(StackNode*)malloc(10*sizeof(StackNode));
    if(!p)
    {
        printf("Память не выделена");
        exit(1);
    }
    p->next=Stack;
    p->info=pos;
    Stack=p;
}

int Pop()
{
    StackNode *p=Stack;
    int val = 0;
    if (IsEmpty()!=true)
    {
        val=Stack->info;
        Stack=Stack->next;
    }
    free(p);
    return(val);
}

bool IsEmpty()
{
    if(Stack==NULL)
    return(true);
    else
    return(false);
}
