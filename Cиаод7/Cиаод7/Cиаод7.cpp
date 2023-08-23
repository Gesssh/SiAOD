///*4. Напишите программу, которая с помощью метода поиска в глубину подсчитывает количество связных компонентов для произвольного неориентированного графа.
//Для представления графа в программе использовать списки смежности.Данные о графе вводятся из файла.
//Программа должна вывести для каждой вершины графа номер компоненты связности, к которой относится эта вершина.
//После завершения работы с динамическими структурами данных необходимо освободить занимаемую ими память.*/
//
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Graph
{
public:
    vector<int>* g; /// список смежностей вершин графа
    bool* visit; ///посещена вершина или нет
    int n;///кол-во вершин
    int* comp;///уомпоненты связности
    explicit Graph(int num) : n(num) /// конструктор для графа
    {
        g = new vector<int>[n];
        comp = new int[n];
        visit = new bool[n];/// создание массива посещенных вершин
        for (int i = 0; i < n; i++)/// и присвоение им значений false
        {
            visit[i] = false;
        }
    }

    void add(int first, int second)///добавление вершин в список смежности
    {
        g[first].push_back(second);
        g[second].push_back(first);
    }

    void dfs(int v, int c_num)///поиск в глубину
    {
        visit[v] = true;
        comp[v] = c_num;
        for (int u : g[v])
        {
            if (!visit[u])
            {
                dfs(u, c_num);
            }
        }
    }

    ~Graph()
    {
        for (int i = 0; i < n; i++)
        {
            g[i].clear();
        }
        delete[]g;
    }
};

int main()
{
    setlocale(LC_ALL, "RUS");
    int n = 0, first, second, c_num = 1;
    ifstream input("f.txt");
    if (!input.is_open())
    {
        cout << "Файл не может быть открыт!" << endl;
        exit(1);
    }
    input >> n;
    Graph A(n);
    while (input >> first >> second)
    {
        A.add(first, second);
    }
    input.close();
    for (int i = 0; i < n; i++)
    {
        if (!A.visit[i])
        {
            A.dfs(i, c_num);
            c_num++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Вершина " << i + 1 << " принадлежит к компонентне связности # " << A.comp[i] << endl;
    }
}































//#include <iostream>
//#include <fstream>
//#include <list>
//using namespace std;
//
//class List
//{
//private:
//
//public:
//    int data;// номер вершины
//    std::list<int> array_node; // список смежных вершин
//    int status;// статус вершины
//    //0 - неопознанная вершина
//    //1 - обнаруженная, но не посещенная вершина
//    //2 - обработанная вершина
//    size_t count = 1; // компонента связности 
//};
//
//int main()
//{
//    setlocale(LC_ALL, "rus");
//    const int q = 7;
//    List M[q];
//    
//    for (size_t i = 0; i < q; i++)
//    {
//        M[i].data = i+1; // создание массива вершин
//    }
//
//    int mas[q][q];
//    ifstream fout;
//    fout.open("f.txt"); // окрываем файл для чтения
//    
//    for (size_t i = 0; i < q; i++)
//    {
//        for (size_t j = 0; j < q; j++)
//        {
//           fout >> mas[i][j];
//          // cout << mas[i][j] << "\t";
//        }
//        cout << "\n";
//    }
//
//   
//    for (size_t i = 0; i < q; i++)
//    {
//        if (M[i].status == 2) continue;
//        M[i].status = 2; // отмечаем ее как посещенную
//        for (int j = q - 1; j >= 0; j--)
//        { // проверяем для нее все смежные вершины
//            if (mas[i][j] == 1 && M[j].status != 2)
//            { // если вершина смежная и не обнаружена
//                M[i].array_node.push_back(j+1);
//                M[i].status = 1; // отмечаем вершину как обнаруженную
//            }
//        }
//        cout << "вершина №" << M[i].data << endl; // выводим номер вершины
//        cout << "смежные вершины: ";
//        for (int n : M[i].array_node)
//        {
//            std::cout << n << "\t";
//        }
//
//    }  
//    fout.close();
//    return 0;
//}
