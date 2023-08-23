/**
Используя очередь, решить следующую задачу. Содержимое текстового файла F,
разделенное на строки (не менее пяти строк), переписать в текстовый файл G,
перенося при этом в конец каждой строки все входящие в нее цифры (с сохранением исходного порядка,
как среди цифр, так и среди остальных литер строки).
Для реализации АТД Очередь использовать массив.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define SIZE 100
char Stack[SIZE];
int i,t,k=0,flag;

void init(); // инициализация стека
void Push(int); // положить в стек
int Pop(); // забрать из стека
int Top(); // получить значение верхнего элемента стека
bool IsEmpty(); // проверить, является ли стек пустым

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FILE *F,*G;
    F = fopen("F.txt","r");
    G = fopen("G.txt","r+");

    int j,m,t1=0,e=0;
    char H,space='\n';
    char B[20];
    init(); // инициализация стека
    while(fscanf(F,"%c",&H)!=eof(F))
    {
        if((H>='0')&&(H<='9'))
        {
            j = atoi(&H);flag++;
            Push(j);
        }
        else if((H=='\n')||(H==eof(F)))
        {
            for(i=0;i<flag;i++)
            {
                fprintf(G,"%d",Pop());
            }
            flag=0;k=0;
            fprintf(G,"%c",space);
        }
        else
        {
            fprintf(G,"%c",H);
        }
    }
    for(i=0;i<flag;i++)
    {
                fprintf(G,"%d",Pop());
    }
    if(IsEmpty()==true) printf("Очередь пустая\n"); // проверить,
    else printf("Очередь непустая\n"); //остались ли числа в стеке

    fclose(F);
    fclose(G);

    return 0;
}

// инициализация стека
void init()
{
    t = -1;
}
// положить в стек
void Push(int a)
{
    if(t==SIZE) // проверка на попытку занесенияэлемента в полный стек
    {
        printf("Попытка занесения значения в полную очередь");
        exit(EXIT_FAILURE);
    }
    else
    {
        t = t+1;
        Stack[t] = a;
    }
}
// забрать из стека
int Pop()
{
    if(t == -1) // проверка на попытку забрать элемент из пустого стека
    {
        printf("Попытка чтения из пустой очереди");
        exit(EXIT_FAILURE);
    }
    else
    {
        int val = 0;
        val = Stack[k];
        k++;t--;
        return(val);
}
}
// получить значение верхнего элемента стека
int Top()
{
return(Stack[t]);
}
// проверить, является ли стек пустым
bool IsEmpty()
{
if(t == -1)return(true);
else return(false);
}
