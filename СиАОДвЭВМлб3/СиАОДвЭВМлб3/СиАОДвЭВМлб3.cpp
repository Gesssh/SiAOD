/*
9. Подготовить текстовый файл, содержащий не менее 15 целых чисел. 
Прочитать данные из этого файла и сформировать односвязный список.
Изменить последовательность указателей так, чтобы отрицательные числа находились в начале списка.
Распечатать исходный и итоговый списки.
После завершения работы со списком освободите занимаемую им динамическую память.
*/

#include <iostream>
#include <fstream>

using namespace std;

typedef struct my_list
{
	struct Queue_v
	{
		int value;//
		Queue_v* next;//
	};
	///
	Queue_v* Begin;
	Queue_v* Total;// для просмотра текущего элемента
	Queue_v* End;

	/// инициализация
	void init()
	{
		Begin = nullptr;
		End = nullptr;
	}

	void add(int elem) 
	{
		Queue_v* ptr;
		ptr = new Queue_v;//
		if (ptr == nullptr)
		{
			cout << "Недостаточно памяти." << endl;
			exit(1);
		}

		ptr->value = elem;
		ptr->next = nullptr;
		if (Begin == nullptr)
		{
			Begin = ptr;
			Total = Begin;
		}
		else
			End->next = ptr;

		End = ptr;
	}

	//с пробежкой по эл-там
	bool get(int* val)
	{
		if (Total == nullptr)
		{
			Total = Begin;
			return false;
		}

		Queue_v* ptr;
		ptr = Total;
		*val = Total->value;
		Total = ptr->next;
		return true;
	}
} my_list;

int main();

int main() 
{
	setlocale(LC_ALL, "RUS");
	int buff, x;
	my_list L1{}, L2{};

	L1.init();
	L2.init();

	ifstream fin1("first.txt");// открыли 1 тхт

	if (!fin1.is_open()) 
	{ // если файл не открыт
		cout << "Файл не может быть открыт!\n"; // сообщить об этом
		exit(1);
	}

	while (!fin1.eof()) 
	{// заполнение первого списка
		fin1 >> buff;
		if (buff < 0)
		{
			L2.add(buff);
		}
		L1.add(buff);
	}

	cout << "Изначальный список список: " << endl;

	while (true)
	{
		if (!L1.get(&x)) 
			break;
		if (x >= 0)
		{
			L2.add(x);
		}

		cout << " " << x;
	}
	fin1.close();

	cout << "\nИзмененный список: " << endl;

	while (true)
	{
		if (!L2.get(&x))
			break;

		cout << " " << x;
	}


	cout << "\n\nПрограмма завершена. ";
	return 0;
}