/**
��������� �������, ������ ��������� ������. ���������� ���������� ����� F,
����������� �� ������ (�� ����� ���� �����), ���������� � ��������� ���� G,
�������� ��� ���� � ����� ������ ������ ��� �������� � ��� ����� (� ����������� ��������� �������,
��� ����� ����, ��� � ����� ��������� ����� ������).
��� ���������� ��� ������� ������������ ������.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define SIZE 100
char Stack[SIZE];
int i,t,k=0,flag;

void init(); // ������������� �����
void Push(int); // �������� � ����
int Pop(); // ������� �� �����
int Top(); // �������� �������� �������� �������� �����
bool IsEmpty(); // ���������, �������� �� ���� ������

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
    init(); // ������������� �����
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
    if(IsEmpty()==true) printf("������� ������\n"); // ���������,
    else printf("������� ��������\n"); //�������� �� ����� � �����

    fclose(F);
    fclose(G);

    return 0;
}

// ������������� �����
void init()
{
    t = -1;
}
// �������� � ����
void Push(int a)
{
    if(t==SIZE) // �������� �� ������� ����������������� � ������ ����
    {
        printf("������� ��������� �������� � ������ �������");
        exit(EXIT_FAILURE);
    }
    else
    {
        t = t+1;
        Stack[t] = a;
    }
}
// ������� �� �����
int Pop()
{
    if(t == -1) // �������� �� ������� ������� ������� �� ������� �����
    {
        printf("������� ������ �� ������ �������");
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
// �������� �������� �������� �������� �����
int Top()
{
return(Stack[t]);
}
// ���������, �������� �� ���� ������
bool IsEmpty()
{
if(t == -1)return(true);
else return(false);
}
