#include "Testing.h"

void Testing4SumII(Solution& op)
{
	vector<int> nums1 = {1, 2};
	vector<int> nums2 = {-2, -1};
	vector<int> nums3 = {-1, 2};
	vector<int> nums4 = {0, 2};
	
	cout<<"Nums1 = ";
	PrintInputList(nums1);
	cout<<endl<<"Nums2 = ";
	PrintInputList(nums2);
	cout<<endl<<"Nums3 = ";
	PrintInputList(nums3);
	cout<<endl<<"Nums4 = ";
	PrintInputList(nums4);
	cout<<endl;
	auto res = op.fourSumCount(nums1, nums2, nums3, nums4);
	cout<<"Number of sums satisfying the condition = "<<res<<endl;
}
