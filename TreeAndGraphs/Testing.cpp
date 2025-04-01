#include "Testing.h"

template<class T>
void PrintInputList(vector<T>& inp)
{
	for(auto item : inp)
		cout<<item<<" ";
}

template<class T>
void PrintInputMatrix(vector<vector<T> >& inp)
{
	for(auto item1 : inp)
	{
		for(auto item2 : item1)
			cout<<item2<<" ";
		cout<<endl;
	}
}

void Testing::ExecuteOperation(int& choice)
{
	switch(choice)
	{
		case 1:
			TestingWordLadder(op);
			break;
		case 2:
			TestingSurroundedRegion(op);
			break;
		default:
			cout<<"Invalid choice selected... Aborting...\n";
			break;
	}
}

