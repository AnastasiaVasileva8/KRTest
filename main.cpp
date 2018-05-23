#include "calc.h"
#define LIBAPP_CALC_HPP


/*Çàäà÷à ïîèñêà ëåêñèêîãðàôè÷åñêè ïåðâîãî ïóòè íà ãðàôå â ãëóáèíó. */
#include <iostream>
#include <vector>

int main()
{
	
	Spisok A;
	int B, E;
	
	std::vector<int> myvec;
	myvec = { 1, 2, 2, 3, 3, 4, 1, 3, 1, 5,6,6, 0};
	Lref t; 
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
}
