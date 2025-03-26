/* Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 * 
 * Example 1: 
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 *
 * Example 2:
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 *
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution
{
	public:
		vector<int> productExceptSelf(vector<int>& nums)
		{
			int n = nums.size();
			vector<int> answer(n), pref(n), suf(n);
			int i;

			pref[0] = 1;
			for (i = 1; i < n; i++)
			{
				pref[i] = pref[i - 1] * nums[i - 1];
				cout<<"pref["<<i<<"] = "<<pref[i]<<"\n";
			}

			suf[n-1] = 1;
			for(i = n - 2; i >= 0; i--)
			{
				suf[i] = suf[i+1] * nums[i+1];
				cout<<"suf["<<i<<"] = "<<suf[i]<<"\n";
			}

			for(i = 0; i < n; i++)
			{
				answer[i] = pref[i] * suf[i];
				cout<<"answer["<<i<<"] = "<<answer[i]<<"\n";
			}
			//answer = nums;
			return answer;
		}
};

int main()
{
	Solution outp;
	vector<int> inp;
	inp.push_back(1);
	inp.push_back(2);
	inp.push_back(3);
	inp.push_back(4);
	vector<int> res = outp.productExceptSelf(inp);
	cout<<"Input: ";
	for (int i = 0; i < inp.size(); i++)
	{
		cout<<inp[i]<<" ";
	}
	cout<<"\nOutput: ";
	for (int i = 0; i < res.size(); i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
