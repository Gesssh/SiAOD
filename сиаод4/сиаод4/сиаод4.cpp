/*
Напишите программу, которая формирует бинарное дерево поиска, выводит построенное дерево на экран.
Данные могут вводиться с клавиатуры, из файла или генерироваться с помощью генератора случайных чисел.
Выбор способа ввода данных выполняется во время работы программы.
В построенном дереве необходимо определить сумму всех ключей, записанных в не терминальных узлах дерева.
Для реализации АТД «Дерево» используйте динамическое распределение памяти.
Перед завершением работы программы освободить занимаемую динамическую память.
Для этого используйте поэлементное удаление элементов динамической структуры данных.
*/

#include <iostream>
#include <fstream>
#include<locale>

using namespace std;

int c = 0, s = 0;

struct NodeTree
{
	int key; //поле даннх
	NodeTree* Left; //левый потомок
	NodeTree* Right; //правый потомок
};

NodeTree* BinaryTree;

//создать пустое дерево
void CreateTree()
{BinaryTree = NULL;}

//добавить в дерево новый элемент
NodeTree* AddNode(NodeTree* node, int k)
{
	if (node == NULL) //если дерева нет, то формируем корень
	{
		node = new NodeTree; //выделяем память под узел
		if (!node) node = new NodeTree; //проверка выделения памяти
		node->key = k;
		node->Left = NULL;
		node->Right = NULL;
	}
	else if (k < node->key) //условие добавления левого потомка
		{
			node->Left = AddNode(node->Left, k);
		}
		else
			node->Right = AddNode(node->Right, k); //добавление правого потомка

	return node;
}

//удалить дерево
void DeleteTree(NodeTree* node)
{
	if (node != NULL)
	{
		NodeTree* p;
		DeleteTree(node->Left); //удалить левый потомок
		DeleteTree(node->Right); //удалить правый потомок
		p = node;
		node = NULL;
		delete p; //осовбождение памяти
	}
}

//функция печатает дерево в симметричном порядке
void PrintTree(NodeTree* node, int h)
{
	if (node != NULL)
	{
		PrintTree(node->Right, h + 1); //рекурсивный вызов левого поддерева
		for (int i = 0; i < h; i++) cout << " ";
		cout << node->key << endl;
		PrintTree(node->Left, h + 1); //рекурсивный вызов правого поддерева
	}
}

//найти сумму ключей , лежащих на нетирменальных узлах
int sum(NodeTree* node)
{
	if (node != 0)
	{
		sum(node->Left);
		sum(node->Right);
		if (node->Left != NULL || node->Right != NULL) //если левый или правый потомок не пусты,то есть у них есть потомки
			c += node->key; //суммируем эти ключи
	}
	return c;
}

int t;
 
void var()
{
	switch (t)
	{
	case 1:
	{
		int k, f;
		cout << "Введите количество элементов дерева\n"; cin >> f;
		cout << "Введите элементы дерева\n";
		while (f != 0)
		{
			cin >> k; f--;
			BinaryTree = AddNode(BinaryTree, k);
		}
		break;
	}
	case 2:
	{
		int k;
		ifstream input_F("T.txt");
		if (!input_F.is_open()) //если файл не был открыт
		{
			cout << "Файл не открылся\n";
		}
		else
		{
			cout << "Файл открыт\n";
			while (!input_F.eof()) //пока не закончится файл
			{
				input_F >> k; // читаем данные
				cout << "Введено число " << k << endl;
				BinaryTree = AddNode(BinaryTree, k);
			}
		}

		input_F.close();
		break;
	}

	case 3:
	{
		int k, f;
		cout << "Введите количество элементов дерева\n"; cin >> f;
		cout << "Введите элементы дерева\n";
		while (f != 0) 
		{
			k = rand() % 30 + 1; f--;
			cout << "Получено значение " << k << endl;
			BinaryTree = AddNode(BinaryTree, k);
		}
		break;
	}
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	NodeTree* p = NULL;
	CreateTree();
	cout << "Выберите способ ввода значений\n";
	cout << "1)С клавиатуры\n";
	cout << "2)Из файла\n";
	cout << "3)Случайно\n";
	cin >> t;
	var();
	cout << "Двоичное дерево:\n";
	PrintTree(BinaryTree, 0);
	int n = 0;
	cout << "Сумма ключей в нетерминальных узлах = " << sum(BinaryTree);
	DeleteTree(BinaryTree);
}