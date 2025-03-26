/*
 * Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
 * There is only one repeated number in nums, return this repeated number.
 * You must solve the problem without modifying the array nums and using only constant extra space.
 *
 * Example 1:
 * Input: nums = [1,3,4,2,2]
 * Output: 2
 *
 * Example 2:
 * Input: nums = [3,1,3,4,2]
 * Output: 3
 *
 * Example 3:
 * Input: nums = [3,3,3,3,3]
 * Output: 3
 */
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution
{
	public:
		int findDuplicate(vector<int>& nums)
		{
			int start = 0, end = nums.size() - 1;
			while(start < end)
			{
				int mid = start + (end - start) / 2;
				int count = 0;
				for (int n : nums)
				{
					if (n <= mid)
						count++;
				}

				if (count > mid)
					end = mid;
				else
					start = mid + 1;
			}

			return start;
		}
};

int main()
{
	Solution op;
	vector<int> inp1 = {1,3,4,2,2};
	vector<int> inp2 = {3,1,3,4,2};
	vector<int> inp3 = {3,3,3,3,3};

	auto res = op.findDuplicate(inp1);
	cout<<"Repeated number for inp1 = "<<res<<endl;
	res = op.findDuplicate(inp2);
	cout<<"Repeated number for inp2 = "<<res<<endl;
	res = op.findDuplicate(inp3);
	cout<<"Repeated number for inp3 = "<<res<<endl;
	return 0;
}
