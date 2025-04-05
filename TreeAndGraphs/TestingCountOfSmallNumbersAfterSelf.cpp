#include "Testing.h"

void PrintList(vector<int>& inp)
{
	for(auto i : inp)
		cout<<i<<" ";
}

void TestingCountOfSmallNumbersAfterSelf(Solution& op)
{
	vector<int> inp1 = {5, 2, 6, 1};
	cout<<"Input: ";
	PrintList(inp1);
	cout<<endl;
	auto res = op.countSmaller(inp1);
	cout<<"Resultant count: ";
	PrintList(res);
	cout<<endl;

	vector<int> inp2 = {2,1,2,1,3,4,2,1,5};
	cout<<"Input: ";
	PrintList(inp2);
	cout<<endl;
	res = op.countSmaller(inp2);
	cout<<"Resultant count: ";
	PrintList(res);
	cout<<endl;
}
