#include "Testing.h"

void TestingFindTheDuplicateNumber(Solution& op)
{
	vector<int> inp1 = {1,3,4,2,2};
	cout<<"Inp1 : ";
	PrintInputList(inp1);
	cout<<endl;
	auto res = op.findDuplicate(inp1);
	cout<<"Duplicate number in the list: "<<res<<endl;
	vector<int> inp2 = {3,1,3,4,2};
	cout<<"Inp2 : ";
	PrintInputList(inp2);
	cout<<endl;
	res = op.findDuplicate(inp2);
	cout<<"Duplicate number in the list: "<<res<<endl;
	vector<int> inp3 = {3,3,3,3,3};
	cout<<"Inp3 : ";
	PrintInputList(inp3);
	cout<<endl;
	res = op.findDuplicate(inp3);
	cout<<"Duplicate number in the list: "<<res<<endl;
}
