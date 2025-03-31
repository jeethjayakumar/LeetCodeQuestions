#include "Testing.h"

void TestingLongestConsecutiveSequence(Solution& op)
{
	vector<int> inp1 = {100,4,100,1,3,2};
	cout<<"Inp1 : ";
	PrintInputList(inp1);
	cout<<endl;
	int res = op.longestConsecutive(inp1);
	cout<<"Length of longest consecutive sequence = "<<res<<endl;
	vector<int> inp2 = {0,3,7,2,5,8,4,6,0,1};
	cout<<"Inp2 : ";
	PrintInputList(inp2);
	cout<<endl;
	res = op.longestConsecutive(inp2);
	cout<<"Length of longest consecutive sequence = "<<res<<endl;
	vector<int> inp3 = {1,0,1,2};
	cout<<"Inp3 : ";
	PrintInputList(inp3);
	cout<<endl;
	res = op.longestConsecutive(inp3);
	cout<<"Length of longest consecutive sequence = "<<res<<endl;
}
