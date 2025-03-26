#include "Testing.h"

void Testing4SumII(Solution& op)
{
	vector<int> nums1 = {1, 2};
	vector<int> nums2 = {-2, -1};
	vector<int> nums3 = {-1, 2};
	vector<int> nums4 = {0, 2};

	auto res = op.fourSumCount(nums1, nums2, nums3, nums4);
	cout<<"Number of sums satisfying the condition = "<<res<<endl;
}
