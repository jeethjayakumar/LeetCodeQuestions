/*
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
 * You must write an algorithm that runs in O(n) time.
 *
 * Example 1:
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 *
 * Example 2:
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 *
 * Example 3:
 * Input: nums = [1,0,1,2]
 * Output: 3
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

class Solution
{
	public:
		int longestConsecutive(vector<int>& nums)
		{
			int maxLength = 0, length = 1, prev, count = 0;
			set<int> numSet;
			for(int i = 0; i < nums.size(); i++)
			{
				numSet.insert(nums[i]);		
			}

			
			for (auto it : numSet)
			{
//				cout<<"count = "<<count<<"  it = "<<it<<endl;
				if (count != 0)
				{
//					cout<<"prev = "<<prev<<"  length = "<<length<<"  maxLength = "<<maxLength<<endl;
					if (it == (prev + 1))
					{
						length ++;
					}
					else
					{
						if(length > maxLength)
							maxLength = length;
						length = 1;
					}
				}
				prev = it;
				count ++;
//				cout<<it<<" ";
			}
			if (length > maxLength)
				maxLength = length;
//			cout<<endl;
			return maxLength;
		}
};

int main()
{
	Solution op;
	vector<int> inp1 = {100, 4, 200, 1, 3, 2};	
	auto res = op.longestConsecutive(inp1);
	cout<<"Longest consecutive elements length for inp1 = "<<res<<endl;

	vector<int> inp2 = {0, 3,7, 2, 5, 8, 4, 6, 0, 1};
	res = op.longestConsecutive(inp2);
	cout<<"Longest consecutive elements length for inp2 = "<<res<<endl;

	vector<int> inp3 = {1, 0, 1, 2};
	res = op.longestConsecutive(inp3);
	cout<<"Longest consecutive elements length for inp3 = "<<res<<endl;

	vector<int> inp4 = {9,1,-3,2,4,8,3,-1,6,-2,-4,7};
	res = op.longestConsecutive(inp4);
	cout<<"Longest consecutive elements length for inp4 = "<<res<<endl;

	return 0;
}
