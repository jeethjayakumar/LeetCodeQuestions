#include "Testing.h"

void TestingProductOfArrayExceptSelf(Solution& op)
{
	vector<int> inp1 = {1,2,3,4};
	auto res = op.DisplayProductExceptSelf(inp1);
	cout<<"Input Array: ";
	PrintInputList(inp1);
	cout<<endl;
	cout<<"Result: ";
	PrintInputList(res);
	cout<<endl;
}
