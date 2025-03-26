/*
 * Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
 * You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
 * 
 * Example 1:
 * Input: nums = [1,2,0]
 * Output: 3
 *
 * Example 2:
 * Input: nums = [3,4,-1,1]
 * Output: 2
 *
 * Example 3:
 * Input: nums = [7,8,9,11,12]
 * Output: 1
 */
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution
{
	private:
		void swap(int& a, int& b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		}
	public:
		int firstMissingPositive(vector<int>& arr)
		{
			int n = arr.size();
			for (int i = 0; i < n; i++)
			{
				while (arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i]-1])
				{
					swap(arr[i], arr[arr[i]-1]);
				}
			}

			for(int i = 1; i <=n; i++)
			{
				if(i != arr[i - 1])
					return i;
			}

			return n + 1;
		}
};

int main()
{
	vector<int> inp = {1,2,0};
	Solution op;
	auto res = op.firstMissingPositive(inp);
	cout<<"Smallest missing positive = "<<res<<endl;
	vector<int> inp1 = {3,4,-1,1};
	res = op.firstMissingPositive(inp1);
	cout<<"New Smallest missing positive = "<<res<<endl;
	vector<int> inp2 = {7,8,9,11,12};
	res = op.firstMissingPositive(inp2);
	cout<<"New Smallest missing positive for inp2 = "<<res<<endl;
	return 0;
}
