#include "Testing.h"

void TestingProductOfArrayExceptSelf(Solution& op)
{
	vector<int> inp1 = {1,2,3,4};
	auto res = op.DisplayProductExceptSelf(inp1);
	cout<<"Input Array: ";
	for(auto i : inp1)
		cout<<i<<" ";
	cout<<endl;
	cout<<"Result: ";
	for(auto i : res)
		cout<<i<<" ";
	cout<<endl;
}
