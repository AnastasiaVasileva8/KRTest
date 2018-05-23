#pragma once
#include <iostream>
#include <vector>
#include <stack> 
#define _CRT_SECURE_NO_WARNINGS
#ifndef LIBAPP_CALC_HPP
#define LIBAPP_CALC_HPP
using namespace std;
#define TRUE 1
#define FALSE 0
typedef int Boolean;
typedef struct L *Lref; // Тип: указатель на заголовочный узел.
typedef struct T *Tref; // Тип: указатель на дуговой узел.

//Описание типа заголовочного узла.
typedef struct L
{
	int Key; //Имя заголовочного узла.
	int Count; //Количество предшественников.
	Boolean Flag; //Флаг посещения узла при обходе.
	Tref Trail; //Указатель на список смежности.
	Lref Next; //Указатель на следующий узел в списке заголовочных узлов.
} Leader;

//Описание типа дугового узла.
typedef struct T
{
	Lref Id;
	Tref Next;
} Trailer;

//Описание типа узла стека.
typedef Tref TipElement;
typedef struct Zveno *svqz;
typedef struct Zveno
{
	TipElement Element; //Указатель на список смежности.
	svqz Sled;
} St;

class Spisok
{
private:
	Lref Head; //Указатель на голову списка заголовочных узлов.
	Lref Tail; //Указатель на фиктивный элемент 
	// в конце списка заголовочных узлов.
	void SearchGraph(int, Lref *);
	void W_S(svqz *, TipElement);
	void DeleteEl(svqz *, TipElement *);
public:
	Spisok() {//Инициализация списка заголовочных узлов.
		Head = Tail = new (Leader);
	}
	Lref GetHead() { return Head; }
	Lref GetTail() { return Tail; }
	//void MakeGraph();
	bool MakeGraph(std::vector<int>);
	void PrintGraph();
	std::vector<int>  Path_Depth_First_Search(int, int);
	};

//void main()
//{
//	setlocale(LC_ALL, "Rus");
//	Spisok A;
//	int B, E;
//	Lref t; //Рабочий указатель для перемещения 
//	// по списку заголовочных звеньев.
//	//Построение графа и вывод его структуры Вирта.
//	A.MakeGraph();
//	A.PrintGraph(); cout << endl;
//	//Определение пути между двумя заданными вершинами графа.
//	t = A.GetHead();
//	while (t != A.GetTail())
//	{
//		(*t).Flag = TRUE; t = (*t).Next;
//	}
//	cout << "Введите начальную вершину пути: "; cin >> B;
//	cout << "Введите конечную вершину пути : "; cin >> E;
//	cout << "Искомый путь: ";
//	A.Path_Depth_First_Search(B, E); cout << endl;
//	system("pause");
//}

void Spisok::SearchGraph(int w, Lref *h)
//Функция возвращает указатель на заголовочный узел 
//с ключом w в графе, заданном структурой Вирта с указателем Head. 
{
	*h = Head; (*Tail).Key = w;
	while ((**h).Key != w) *h = (**h).Next;
	if (*h == Tail)
		//В списке заголовочных узлов нет узла с ключом w.
		//Поместим его в конец списка Head.
	{
		Tail = new (Leader); (**h).Count = 0;
		(**h).Trail = NULL; (**h).Next = Tail;
	}
}

//void Spisok::MakeGraph()
bool Spisok::MakeGraph(std::vector<int> myvect)
//Функция возвращает указатель Head на структуру
//Вирта, соответствующую ориентированному графу.
{
	if (!myvect.empty())
	{
		int x, y;
		Lref p, q; //Рабочие указатели.
		Tref t, r; //Рабочие указатели.
		Boolean Res; //Флаг наличия дуги.
		int i = 0;
		x = myvect[i];
		i++;
		while (x != 0)
		{
			y = myvect[i];
			i++;
			//Определим, существует ли в графе дуга (x,y)?
			SearchGraph(x, &p); SearchGraph(y, &q);
			r = (*p).Trail; Res = FALSE;
			while ((r != NULL) && (!Res))
				if ((*r).Id == q) Res = TRUE;
				else r = (*r).Next;
				if (!Res) //Если дуга отсутствует, то поместим её в граф.
				{
					t = new (Trailer); (*t).Id = q;
					(*t).Next = (*p).Trail; (*p).Trail = t; (*q).Count++;
				}
				x = myvect[i];
				i++;
		}
		return true;
	}
	else
	{

		std::cout << "Граф не существуетю.";
		return false;
	}
}


void Spisok::PrintGraph()
//Вывод структуры Вирта, заданной указателем 
//Head и соответствующей ориентированному графу.
{
	Lref p; //Рабочий указатель.
	Tref q; //Рабочий указатель.

	p = Head;
	while (p != Tail)
	{
		cout << "(" << (*p).Key; q = (*p).Trail;
		while (q != NULL)
		{
			cout << (*(*q).Id).Key; q = (*q).Next;
		}
		cout << ")"; p = (*p).Next; cout << " ";
	}
}

void Spisok::W_S(svqz *stk, TipElement el)
//Помещение элемента el в стек stk.
{
	svqz q = new (St);
	(*q).Element = el; (*q).Sled = *stk; *stk = q;
}

void Spisok::DeleteEl(svqz *stk, TipElement *klad)
//Удаление звена из стека, заданного указателем *stk. 
//Значение информационного поля удаляемого звена сохраня- 
//ется в параметре klad.
{
	svqz q;

	if (*stk == NULL) cout << "Попытка выбора из пустого стека!\n";
	else
	{
		*klad = (**stk).Element; q = *stk; *stk = (**stk).Sled; delete q;
	}
}

std::vector<int> Spisok::Path_Depth_First_Search(int B, int E)
//Путь между вершинами B и E в графе, заданном указателем Head.
{
	Lref s, r = 0; //
	Tref t;
	svqz TempU; //Рабочий указатель для перемещения по стеку.                
	std::vector<int>ResVec;
	int i;
	svqz Stack = NULL; //Стек пуст.
	//Определим указатель на вершину B
	s = Head;
	
	while (s != Tail)//1
	{
		if (s->Key == B)  r = s;
		s = s->Next;
	}
	//Посетим первую непосещенную вершину графа и 
	//поместим ее в первоначально пустой стек.
	if (r->Key == E)//2 ==................................................
	{
		TempU = Stack;
		while (TempU != NULL)//3
		{
			cout << TempU->Element->Id->Key << " ";
			ResVec.push_back(TempU->Element->Id->Key);
			TempU = TempU->Sled;
		}

		cout << B << endl;
		ResVec.push_back(B);
	}
	r->Flag = FALSE; W_S(&Stack, r->Trail);
	
	while (Stack != NULL)//4
	{
		//Рассмотрим "верхушку" стека.
		t = Stack->Element;
		if (t->Id->Trail != NULL)//5
			//У рассматриваемой вершины есть смежные вершины.
		{
			if (t->Id->Flag)//6
				//У рассматриваемой вершины есть
				//непосещенные смежные вершины.
			{
				//Посетим рассматриваемую вершину
				//и поместим указатель на ее список смежности в стек.
				if (t->Id->Key == E)//7 ==,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
				{
					TempU = Stack;
					while (TempU != NULL)//8
					{
						cout << TempU->Element->Id->Key << " ";
						ResVec.push_back(TempU->Element->Id->Key);
						TempU = TempU->Sled;
					}

					cout << B << endl;
					ResVec.push_back(B);
				}
				t->Id->Flag = FALSE;
				W_S(&Stack, t->Id->Trail);
			
			}
			//У рассматриваемой вершины нет
			//непосещенных смежных вершин.
			else//9
			{
				t = Stack->Element;
				if (t->Next != NULL)//10
					//Заменяем верхушку стека указателем 
					//на следующий элемент списка смежности...
				{
					DeleteEl(&Stack, &t);
					W_S(&Stack, t->Next);
					
				}
				//или удаляем верхушку стека.
				else  DeleteEl(&Stack, &t);//11
			}
		}
		//У рассматриваемой вершины нет смежных вершин.
		else//12
		{
			if (t->Id->Flag)//13
				//Посетим рассматриваемую вершину.
			{
				if (t->Id->Key == E) //14 ==,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
				{
					TempU = Stack;
					while (TempU != NULL)//15
					{
						cout << TempU->Element->Id->Key << " ";
						ResVec.push_back(TempU->Element->Id->Key);
						TempU = TempU->Sled;
					}

					cout << B << endl;
					ResVec.push_back(B);
				}
				t->Id->Flag = FALSE;
			
			}
			t = Stack->Element;
			if (t->Next != NULL)//16
				//Заменяем верхушку стека указателем 
				//на следующий элемент списка смежности...
			{
				DeleteEl(&Stack, &t);
				W_S(&Stack, t->Next);
			}
			//или удаляем верхушку стека.
			else  DeleteEl(&Stack, &t);//17
		}
		
	}
	
	//ResVec.push_back('0');//инекция ошибок лр4
	//reverse(ResVec.begin(), ResVec.end());
//met
	return ResVec;
}
#endif

	


