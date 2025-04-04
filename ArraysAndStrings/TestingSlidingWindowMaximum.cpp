#include "Testing.h"

void TestingSlidingWindowMaximum(Solution& op)
{
	vector<int> inp1 = {1,3,-1,-3,5,3,6,7};
	cout<<"Input list inp1: ";
	PrintInputList(inp1);
	cout<<endl;
	int k1 = 3;
	cout<<"Input sliding window size: "<<k1<<endl;
	vector<int> out1 = op.maxSlidingWindow(inp1, k1);
	cout<<"Sliding Window output: ";
	PrintInputList(out1);
	cout<<endl;

	vector<int> inp2 = {1};
	int k2 = 1;
	cout<<"Input list inp2: ";
	PrintInputList(inp2);
	cout<<endl;
	cout<<"Input sliding window size: "<<k2<<endl;
	vector<int> out2 = op.maxSlidingWindow(inp2, k2);
	cout<<"Sliding Window output: ";
	PrintInputList(out2);
	cout<<endl;
}
