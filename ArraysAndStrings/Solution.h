#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution
{
	public:
		vector<int> DisplayProductExceptSelf(vector<int>& nums);
		vector<int> DisplaySpiralOrder(vector<vector<int> >& matrix);
		int fourSumCount(vector<int>& num1, vector<int>& num2, vector<int>& num3, vector<int>& num4);
		int calcuteAreaContainingMostWater(vector<int>& height);
		void gameOfLife(vector<vector<int> >& inp);
		int firstMissingPositive(vector<int>& nums);
		int longestConsecutive(vector<int>& nums);
		int findDuplicate(vector<int>& nums);
		int calculate(string s);
		vector<int> maxSlidingWindow(vector<int>& nums, int& k);
		string minWindow(string s, string t);
};
