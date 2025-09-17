#include "Solution.h"
#include <unordered_map>
#include <set>
#include <stack>
#include <climits>
#include <queue>
/*
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 * Example: 
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 *
 * Solution implemented: This would require 2 arrays - one for forward iteration and one for backward iteration
 * In the first array, while iterating multiply the previous result and previous number and save it in current index. 
 * Do the same thing for second array but iteration should be on opposite direction.
 * The resultant array will be the product of those 2 iterations.
 *
 * Time Complexity : O(n)
 * Space Complexity : O(n)
 */
vector<int> Solution::DisplayProductExceptSelf(vector<int>& nums)
{
	int n = nums.size();
	vector<int> pref(n, 0), suf(n, 0), outp(n, 0);

	pref[0] = 1;
	for(int i = 1;i < n;i ++)
	{
		pref[i] = nums[i-1] * pref[i-1];
	}

	suf[n-1] = 1;
	for(int i = n - 2; i >= 0; i--)
	{
		suf[i] = suf[i+1] * nums[i+1];
	}

	for(int i = 0; i < n; i++)
	{
		outp[i] = pref[i] * suf[i];
	}

	return outp;
}

/*
 * Given an m x n matrix, return all elements of the matrix in spiral order
 * Example 1:
 *  Input: matrix = [[1,2,3],
 *                   [4,5,6],
 *                   [7,8,9]]
 *  Output: [1,2,3,6,9,8,7,4,5]
 *
 *  Solution implemented: This would require definition of directions a cell can go (row-wise and column-wise) and visited table to identify if a specific cell has been visited or not.
 *
 */
//vector<int> Solution::DisplaySpiralOrder(vector<vector<int> >& matrix)
//{
//	vector<int> dr = {0, 1, 0, -1};
//	vector<int> dc = {1, 0, -1, 0};
//	int rSize = matrix.size();
//	int cSize = matrix[0].size();
//	vector<int> res(rSize * cSize);
//	vector<vector<bool> > visited(rSize, vector<bool>(cSize, false));
//
//	int r = 0, c = 0, idx = 0;
//
//	for(int i = 0; i < rSize*cSize; i++)
//	{
//		res[i] = matrix[r][c];
//		visited[r][c] = true;
//		int newR = r + dr[idx];
//		int newC = c + dc[idx];
//
//		if (newR >= 0 && newR < rSize &&
//		    newC >= 0 && newC < cSize &&
//		    !visited[newR][newC])
//		{
//			r = newR;
//			c = newC;
//		}
//		else
//		{
//			idx = (idx + 1) % 4;
//			r = r + dr[idx];
//			c = c + dc[idx];
//		}
//	}
//	
//	return res;
    vector<int> Solution::DisplaySpiralOrder(vector<vector<int> >& matrix)
    {
        int rSize = matrix.size();
        if (rSize == 0) return {};
        int cSize = matrix[0].size();
        vector<int> res;
        res.reserve(rSize * cSize);

        int top = 0, bottom = rSize - 1, left = 0, right = cSize - 1;

        while (top <= bottom && left <= right)
        {
            for (int j = left; j <= right; ++j)
                res.push_back(matrix[top][j]);
            ++top;

            for (int i = top; i <= bottom; ++i)
                res.push_back(matrix[i][right]);
            --right;

            if (top <= bottom)
            {
                for (int j = right; j >= left; --j)
                    res.push_back(matrix[bottom][j]);
                --bottom;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; --i)
                    res.push_back(matrix[i][left]);
                ++left;
            }
        }

        return res;
    }
//}

/*
 * Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:
 * a) 0 <= i, j, k, l < n
 * b) nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 *
 * Example 1:
 * Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
 * Output: 2
 * Explanation:
 * The two tuples are:
 * 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
 *
 * Solution Implemented: Given 4 arrays, split them into 2 sets. Add numbers in first set of array and save in a separate counter called sum (unordered_map).
 * While adding the numbers in second set of array, we check if that sum is present in counter or not.
 *
 */
int Solution::fourSumCount(vector<int>& num1, vector<int>& num2, vector<int>& num3, vector<int>& num4)
{
	unordered_map<int, int> sum;
	int count = 0;

	for(auto n1: num1)
	{
		for(auto n2: num2)
		{
			sum[n1+n2] ++;
		}
	}

	for(auto n3: num3)
	{
		for(auto n4: num4)
		{
			auto it = sum.find(0 - (n3 + n4));
			if (it != sum.end())
				count += it->second;
		}
	}

	return count;
}

/*
 * Given an integer array height of length n. Find two lines that together with the x-axis form a container, such that the container contains the most water.
 * Return the maximum amount of water a container can store.
 * Example 1:
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 *
 * Solution Implemented: Iterate the height list from both end and compare the heights. If the height at the beg position is < height at end position,
 * then move the index at the lower height end.
 *
 */
int Solution::calcuteAreaContainingMostWater(vector<int>& height)
{
	int max_area = 0, area = 0;
	int left = 0, right = height.size() - 1;

	while(left < right)
	{
		if(height[left] < height[right])
		{
			area = height[left] * (right - left);
			if (area > max_area)
				max_area = area;
			left ++;
		}
		else
		{
			area = height[right] * (right - left);
			if (area > max_area)
				max_area = area;
			right --;
		}
	}
	return max_area;
}

/*
 * The board is made up of an m x n grid of cells, where each cell has an initial state: 
 * live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal)
 * using the following four rules (taken from the above Wikipedia article):
 * 1. Any live cell with fewer than two live neighbors dies as if caused by under-population.
 * 2. Any live cell with two or three live neighbors lives on to the next generation.
 * 3. Any live cell with more than three live neighbors dies, as if by over-population.
 * 4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 * Given the current state of the board, update the board to reflect its next state.
 *
 * Solution Implemented: This is implemented similar to Spiral Order matrix exercise.
 * We use separate array for tracking direction to traverse when I'm on a cell and check if the population on the cell is alive or not.
 *
 */
void Solution::gameOfLife(vector<vector<int> >& board)
{
	int nRow = board.size(), nCol = board[0].size();
	vector<vector<bool> > changed(nRow, vector<bool>(nCol, false));
	vector<int> nDirRow = {-1, -1, -1, 0, 1, 1,  1,  0};
	vector<int> nDirCol = {-1,  0,  1, 1, 1, 0, -1, -1};

	for(int i = 0; i < nRow; i++)
	{
		for(int j = 0; j < nCol; j++)
		{
			int cnt = 0;
			for(int k = 0; k < nDirRow.size(); k++)
			{
				int newR = i + nDirRow[k];
				int newC = j + nDirCol[k];
				if(newR >= 0 && newR < nRow &&
				   newC >= 0 && newC < nCol)
				{
					if(board[newR][newC] && !changed[newR][newC])
						cnt++;
					if(!board[newR][newC] && changed[newR][newC])
						cnt++;
				}

			}
			if (!board[i][j])
			{
				if (cnt == 3)
				{
					board[i][j] = 1;
					changed[i][j] = true;
				}
			}
			else
			{
				if (cnt < 2 || cnt > 3)
				{
					board[i][j] = 0;
					changed[i][j] = true;
				}

			}
		}
	}
}

/*
 * Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
 * You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
 *
 * Solution implemented: Approach taken is similar to cyclic sort.
 */

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int Solution::firstMissingPositive(vector<int>& nums)
{
	int n = nums.size();

	for(int i = 0; i < n; i++)
	{
		while(nums[i] >= 1 && nums[i] <= n &&
		      nums[i] != nums[nums[i]-1])
		{
			swap(nums[i], nums[nums[i]-1]);
		}
	}

	for(int i = 1; i <= n; i++)
	{
		if(i != nums[i - 1])
			return i;
	}
	return n+1;
}

/*
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
 * You must write an algorithm that runs in O(n) time
 *
 * Solution implemented : First you iterate the list and put it in ordered container like set.
 * When traversing through set, we see if prev item is one less than the current one. If yes then we increment the length.
 * If not, we compare the length with maxLength and save the greatest value.
 *
 */
int Solution::longestConsecutive(vector<int>& nums)
{
	set<int> orderedList(nums.begin(), nums.end());
	int length = 1, maxLength = 0, prev = 0, count = 0;
	for(auto it : orderedList)
	{
		if (count != 0)
		{
			if (it == (prev + 1))
			{
				length ++;
			}
			else
			{
				if (length > maxLength)
					maxLength = length;
				length = 1;
			}
		}
		prev = it;
		count ++;
	}
	if (length > maxLength)
		maxLength = length;
	return maxLength;
}

/*
 * Given an array of integers nums containing n+1 integers where where each integer is in the range [1, n] inclusive, there is only one repeated number. 
 * Return this repeated number.
 * You must solve the problem without modifying the array nums and using only constant extra space.
 *
 * Solution implemented: A variation of binary search algorithm is implemented here. We know that size of the input array - 1 is the max number it may contain.
 * We use that information as leverage to find the one duplicate number. Although this method will not be applicable if there are more than on integers that has duplicate.
 * Time complexity here is O(nlogn)
 *
 */
int Solution::findDuplicate(vector<int>& nums)
{
	int start = 0, end = nums.size() - 1, cnt =0, mid = 0;
	while(start < end)
	{
		mid = start + (end - start)/2;
		cnt = 0;
		for(auto n : nums)
		{
			if(n <= mid)
				cnt ++;
		}

		if (cnt > mid)
			end = mid;
		else
			start = mid + 1;
	}
	return start;
}

/*
 * Given a string s which represents an expression, evaluate this expression and return its value. 
 * You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval()
 *
 * Solution Implemented:
 *
 *
 */
int Solution::calculate(string s)
{
	stack<int> nStack;
	int stSize = s.size();
	int top = 0;
	char prevOp='+';
	int num = 0, res = 0;

	for(int i = 0; i < stSize; i++)
	{
		if(isdigit(s[i]))
			num = (num * 10) + (s[i] - '0');
		if (i == stSize - 1 || (s[i] == '+') ||(s[i] == '-') || (s[i] == '*') || (s[i] == '/'))
		{
			if(!nStack.empty()) top = nStack.top();
			switch(prevOp)
			{
				case '+':
					nStack.push(num);
					break;
				case '-':
					nStack.push(-num);
					break;
				case '*':
					nStack.pop();
					nStack.push(top * num);
					break;
				case '/':
					nStack.pop();
					nStack.push(top / num);
					break;
				default:
					break;
			}
			prevOp = s[i];
			num = 0;
		}
	}

	while(!nStack.empty())
	{
		res += nStack.top();
		nStack.pop();
	}

	return res;
}

/*
 * Given array of int nums and sliding window size k, return the max sliding window - array where each time we move the window by one position
 * the highest element in the k numbers in the array should be displayed.
 * Eg: inp = {1,3,-1, -3,5,3,6,7}, k=3, outp = {3,3,5,5,6,7}
 *
 * Solution Implemented: Here we use deque such that front insertion is always for indexes having greater value in a particular k window.
 * Insertion of indices happens on backside of deque.
 */
vector<int> Solution::maxSlidingWindow(vector<int>& nums, int& k)
{
	vector<int> res;
	deque<int> dq;

	for(int i = 0; i < nums.size(); i++)
	{
		if(!dq.empty() && (i - k) >= dq.front())
		{
			dq.pop_front();
		}

		while(!dq.empty() && nums[dq.back()]<= nums[i])
			dq.pop_back();
		dq.push_back(i);
		if (i >= k-1)
			res.push_back(nums[dq.front()]);
	}

	return res;
}

/*
 * LeetCode 76
 * Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates)
 * is included in the window. If there is no such substring, return the emptry string.
 * Eg: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
 *
 * Solution implemented: First we track characters in string t and its occurances. Then we traverse through each characters in string s.
 * On each s traversal, we track the character occurances in separate array. Each time if a character in s is found in t then a match is found and match is increment.
 * That will be the starting point of the substring in s and a separate loop will be executed till match value becomes length of t.
 * Time complexity : O(len(s) * len(t))
 */
string Solution::minWindow(string s, string t)
{
	vector<int> tNeeded(128, 0), sHave(128, 0); // Total ASCII Characters to track counter
	int minStart = -1, minLen = INT_MAX, start = 0, matches = 0;

	for(auto c : t)
		tNeeded[c]++;

	for(int i = 0; i < s.length(); i++)
	{
		sHave[s[i]]++;
		if(tNeeded[s[i]] >= sHave[s[i]])
			matches++;
		while(matches == t.length())
		{
			if((i - start + 1) < minLen)
			{
				minLen = i - start + 1;
				minStart = start;
			}

			if (tNeeded[s[start]] >= sHave[s[start]])
				matches--;
			sHave[s[start]]--;
			start++;
		}
	}

	return minStart < 0 ? "" : s.substr(minStart, minLen);
}

/*
 * LeetCode 215
 * Given an array arr[] and an integer k, the task is to find k largest elements in the given array. Elements in the output array should be in decreasing order.
 * Example:
 * Input:  [1, 23, 12, 9, 30, 2, 50], k = 3
 * Output: [50, 30, 23]
 * 
 * Solution Implemented: Used priority_queue to populate and identify largest elements.
 * Time Complexity : O(n log K)
*/

vector<int> Solution::findKLargestElements(vector<int>& inp, int& k)
{
	priority_queue<int, vector<int>, greater<int> > minH(inp.begin(), inp.begin() + k);

	for (int i = k; i < inp.size(); i++)
	{
		if (minH.top() < inp[i])
		{
			minH.pop();
			minH.push(inp[i]);
		}
	}

	vector<int> res;
	while (!minH.empty())
	{
		res.push_back(minH.top());
		minH.pop();
	}
	return res;
}

/*
 *	Amazon Interview Question:
 *  Given input list of strings words = {} and prefix = "", return list of strings from the words list that starts with prefix
 *  Note: words list can be big list and each time when user types prefix, this method should return the results in optimal time.
 *  Example :
 *  Input : words = {"apple", "book", "banana", "bathroom", "batman", "cat", "batman"}
 *  Prefix = "bat"
 *  Output = "bathroom", "batman"
 */
void Trie::insert(const string& word)
{
	TrieNode* node = root;
	for (char c : word)
	{
		if (!node->children[c])
			node->children[c] = new TrieNode();
		node = node->children[c];
	}
	node->isWord = true;
}

void Trie::dfs(TrieNode* node, const string& prefix, vector<string>& res)
{
	if (node->isWord)
		res.push_back(prefix);

	for (auto& [ch, child] : node->children)
	{
		dfs(child, prefix + ch, res);
	}
}

vector<string> Trie::startsWith(const string& prefix)
{
	vector<string> res;
	TrieNode* node = root;

	for (char c : prefix)
	{
		if (!node->children.count(c))
			return res;

		node = node->children[c];
	}

	dfs(node, prefix,res);

	return res;
}

vector<string> Solution::FindStringsForPrefix(vector<string>& words, const string& prefix)
{
	Trie trie;

	for (auto& w : words)
	{
		trie.insert(w);
	}

	auto res = trie.startsWith(prefix);
	return res;
}