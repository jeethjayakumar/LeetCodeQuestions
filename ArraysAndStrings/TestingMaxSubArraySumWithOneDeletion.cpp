#include "Testing.h"

void TestingMaxSubArraySumWithOneDeletion(Solution& op)
{
	vector<int> inp1 = { 1,2,3,4 };
	auto res = op.maximumSum(inp1);
	cout << "Input Array: ";
	PrintInputList(inp1);
	cout << endl;
	cout << "Output sum = " << res;
	cout << endl;

	vector<int> inp2 = { 1,-2,0,3 };
	res = op.maximumSum(inp2);
	cout << "Input Array: ";
	PrintInputList(inp2);
	cout << endl;
	cout << "Output sum = " << res;
	cout << endl;

	vector<int> inp3 = { 1, -2,-2, 3 };
	res = op.maximumSum(inp3);
	cout << "Input Array: ";
	PrintInputList(inp3);
	cout << endl;
	cout << "Output sum = " << res;
	cout << endl;
}
