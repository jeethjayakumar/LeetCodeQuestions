#include "Testing.h"

void printList(vector<int>& nums)
{
	for(auto n : nums)
		cout<<n<<" ";
}
void TestingFirstMissingPositive(Solution& op)
{
	vector<int> inp1 = {1, 2, 0};
	cout<<"Inp1 : ";
	printList(inp1);
	cout<<endl;
	auto res = op.firstMissingPositive(inp1);
	cout<<"First missing positive number for inp1 list = "<<res<<endl;
	vector<int> inp2 = {3, 4, -1, 1};
	cout<<"Inp2 : ";
	printList(inp2);
	cout<<endl;
	res = op.firstMissingPositive(inp2);
	cout<<"First missing positive number for inp2 list = "<<res<<endl;
	vector<int> inp3 = {7, 8, 9 , 11, 12};
	cout<<"Inp3 : ";
	printList(inp3);
	cout<<endl;
	res = op.firstMissingPositive(inp3);
	cout<<"First missing positive number for inp3 list = "<<res<<endl;
}
