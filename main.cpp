#include "calc.h"
#define LIBAPP_CALC_HPP


/*Çàäà÷à ïîèñêà ëåêñèêîãðàôè÷åñêè ïåðâîãî ïóòè íà ãðàôå â ãëóáèíó. */
#include <iostream>
//#include <stack> // ñòåê
//using namespace std;
//int main()
//{
//	system("chcp 1251");
//	system("cls");
//	
//	int const n = 5;
//	int mas[n][n] = {
//		/*{ 0, 1, 1, 0, 0 },
//		{ 1, 0, 0, 1, 0 },
//		{ 1, 0, 0, 0, 1 },
//		{ 0, 1, 0, 0, 0 },
//		{ 0, 0, 1, 0, 0 }*/
//		{ 0, 1, 1, 1, 0 },
//		{ 1, 0, 1, 1, 0 },
//		{ 1, 1, 0, 1, 1 },
//		{ 1, 1, 1, 0, 1 },
//		{ 0, 0, 1, 1, 0 }
//	};
//	int req;
//	cout << "Íà÷àëüíàÿ âåðøèíà = 1" << endl;
//	cout << "Êîíå÷íàÿ âåðøèíà = ";
//	cin >> req;
//	cout << endl;
	//   { 0, 0, 1, 1, 0, 0, 0 }, // ìàòðèöà ñìåæíîñòè
	//{ 1, 0, 0, 0, 0, 0, 0 },
	//{ 1, 0, 0, 0, 1, 0, 0 },
	//{ 1, 0, 0, 0, 1, 0, 0 },
	//{ 0, 0, 0, 1, 0, 1, 1 },
	//{ 0, 0, 1, 0, 1, 0, 0 },
	//{ 0, 0, 0, 0, 1, 0, 0 } };
	//{ 0, 1, 1, 0, 0, 0, 0 }, // ìàòðèöà ñìåæíîñòè
	//{ 1, 0, 1, 0, 0, 0, 0 },
	//{ 1, 1, 0, 1, 1, 0, 0 },
	//{ 0, 0, 1, 0, 1, 0, 0 },
	//{ 0, 0, 1, 1, 0, 1, 1 },
	//{ 0, 0, 0, 0, 1, 0, 0 },
	//{ 1, 0, 0, 0, 1, 0, 0 }
//    mySearch(mas, req);
//	cin.get(); cin.get();
//	return 0;
//}

#include <vector>

void main()
{
	
	Spisok A;
	int B, E;
	
	std::vector<int> myvec;
	myvec = { 1, 2, 2, 3, 3, 4, 1, 3, 1, 5,6,6, 0};
	Lref t; //Ðàáî÷èé óêàçàòåëü äëÿ ïåðåìåùåíèÿ 
	// ïî ñïèñêó çàãîëîâî÷íûõ çâåíüåâ.
	//Ïîñòðîåíèå ãðàôà è âûâîä åãî ñòðóêòóðû .
	//myvec =  { 1, 2, 2, 3, 3, 4, 1, 3, 1, 5,6,6, 0 };
	//
	////Ïîñòðîåíèå ãðàôà è âûâîä åãî ñòðóêòóðû Âèðòà.
	A.MakeGraph(myvec);
	//A.MakeGraph();
	A.PrintGraph(); cout << endl;
	//Îïðåäåëåíèå ïóòè ìåæäó äâóìÿ çàäàííûìè âåðøèíàìè ãðàôà.
	t = A.GetHead();
	while (t != A.GetTail())
	{
		(*t).Flag = TRUE; t = (*t).Next;
	}
	 cin >> B;
	 cin >> E;
	A.Path_Depth_First_Search(B, E); cout << endl;

	//setlocale(LC_ALL, "Russian");
	//Spisok A;
	//char B, E;
	//Lref t; //Ðàáî÷èé óêàçàòåëü äëÿ ïåðåìåùåíèÿ  ïî ñïèñêó çàãîëîâî÷íûõ çâåíüåâ.

	//char x, y;
	/*std::vector<int> myvec = {};*/
	////std::cout << "Ââîäèòå íà÷àëüíóþ âåðøèíó äóãè: ";
	////std::cin >> x;
	////
	////while (x != 0)
	////{
	//	myvec.push_back(x);
	////	std::cout << "Ââîäèòå êîíå÷íóþ âåðøèíó äóãè: ";
	////	std::cin >> y;
	////	//Îïðåäåëèì, ñóùåñòâóåò ëè â ãðàôå äóãà (x,y)?
	////
	////	myvec.push_back(y);
	////	std::cout << "Ââîäèòå íà÷àëüíóþ âåðøèíó äóãè: ";
	////	std::cin >> x;
	////	myvec.push_back(x);
	////}
	//myvec = { 1, 2, 2,2,2, 3, 3, 6, 6, 8, 1, 4, 4, 5, 5, 8, 1, 5, 0 };
	//
	////Ïîñòðîåíèå ãðàôà è âûâîä åãî ñòðóêòóðû Âèðòà.
	//A.MakeGraph(myvec);
	//A.PrintGraph(); cout << endl;
	////Îïðåäåëåíèå ïóòè ìåæäó äâóìÿ çàäàííûìè âåðøèíàìè ãðàôà.
	//t = A.GetHead();
	//while (t != A.GetTail())
	//{
	//	(*t).Flag = TRUE; t = (*t).Next;
	//}
	//cout << "Ââåäèòå íà÷àëüíóþ âåðøèíó ïóòè: "; cin >> B;
	//cout << "Ââåäèòå êîíå÷íóþ âåðøèíó ïóòè : "; cin >> E;
	//cout << "Èñêîìûé ïóòü: ";
	//A.Go_width(A.GetHead(), B, E);
	//cout << endl;
	//system("pause");
}
