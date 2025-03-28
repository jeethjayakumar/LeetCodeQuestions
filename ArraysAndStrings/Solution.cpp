#include "Solution.h"
#include <unordered_map>

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
vector<int> Solution::DisplaySpiralOrder(vector<vector<int> >& matrix)
{
	vector<int> dr = {0, 1, 0, -1};
	vector<int> dc = {1, 0, -1, 0};
	int rSize = matrix.size();
	int cSize = matrix[0].size();
	vector<int> res(rSize * cSize);
	vector<vector<bool> > visited(rSize, vector<bool>(cSize, false));

	int r = 0, c = 0, idx = 0;

	for(int i = 0; i < rSize*cSize; i++)
	{
		res[i] = matrix[r][c];
		visited[r][c] = true;
		int newR = r + dr[idx];
		int newC = c + dc[idx];

		if (newR >= 0 && newR < rSize &&
		    newC >= 0 && newC < cSize &&
		    !visited[newR][newC])
		{
			r = newR;
			c = newC;
		}
		else
		{
			idx = (idx + 1) % 4;
			r = r + dr[idx];
			c = c + dc[idx];
		}
	}
	
	return res;
}

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
