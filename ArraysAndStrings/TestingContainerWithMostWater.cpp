#include "Testing.h"

void TestingContainerWithMostWater(Solution& op)
{
	vector<int> inp1 = {1,8,6,2,5,4,8,3,7};
	cout<<"Inp1 wall height: ";
	for(auto n : inp1)
		cout<<n<<" ";
	cout<<endl;
	auto res = op.calcuteAreaContainingMostWater(inp1);
	cout<<"Area containing most water = "<<res<<endl;

	vector<int> inp2 = {1,1};
	cout<<"Inp2 wall height: ";
	for(auto n : inp2)
		cout<<n<<" ";
	cout<<endl;
	res = op.calcuteAreaContainingMostWater(inp2);
	cout<<"Area containing most water = "<<res<<endl;

	vector<int> inp3 = {};
	res = op.calcuteAreaContainingMostWater(inp3);
	cout<<"Area containing most water for empty height list = "<<res<<endl;
}
