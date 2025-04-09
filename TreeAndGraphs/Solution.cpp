#include "Solution.h"
#include <functional>
#include <set>
#include <unordered_map>
#include <climits>

/*
 * Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
 * Example: 
 * Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
 * Output: 5
 * Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
 *
 * Solution Implemented: We need to treat this problem as graph problem where each word in the list is a node and relation of the word in the list to begin word and end word as edges
 * Best approach to solve this issue is Bidirectional BFS. We first put it in unordered+set to remove duplication. Then we will maintain 2 maps of pair<string, int> to track the words and its respective order found.
 * If through traversal, we found the word thats been common in both maps, then we track that order # as the shortest path.
 * Time complexity : O(N * L * 26) where N will be number of words in the list, L will be the length of the word, 26 are alphabet character numbers.
 */

int Solution::extendQueue(unordered_map<string, int>& CurrentDir, unordered_map<string, int>& OppositeDir, queue<string>& CurrentQueue, unordered_set<string>& words)
{
	string word = CurrentQueue.front();
	CurrentQueue.pop();
	int steps = CurrentDir[word];

	for (int i = 0; i < word.length(); i++)
	{
		char orig = word[i];
		for(char c = 'a'; c <= 'z'; c++)
		{
			if (c == orig) continue;
			word[i] = c;
			if (!words.count(word) || CurrentDir[word]) continue;
			if (OppositeDir[word])
			{
				return (steps + OppositeDir[word]);
			}

			CurrentDir[word] = steps + 1;
			CurrentQueue.push(word);
		}
		word[i] = orig;
	}

	return -1;
}

int Solution::ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	unordered_set<string> words(wordList.begin(), wordList.end());
	if (!words.count(endWord)) return 0;

	unordered_map<string, int> BFS_Beg, BFS_End;
	queue<string> begin{{beginWord}};
	queue<string> end{{endWord}};
	int res;

	BFS_Beg[beginWord] = 1;
	BFS_End[endWord] = 1;

	while (!begin.empty() && !end.empty())
	{
		if (begin.size() <= end.size())
		{
			res = extendQueue(BFS_Beg, BFS_End, begin, words);
		}
		else
		{
			res = extendQueue(BFS_End, BFS_Beg, end, words);
		}

		if (res != -1)
			return res;
	}
	return 0;
}

/*
 * LeetCode 130
 * You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
 * The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
 * To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything
 *
 * Solution implemented: This again is graph problem where each cell is determined as node and path to next cell as edges.
 * Here we took DFS approach. First we will go through the edges to find O and then use DFS method to replace those O as '.'
 * Then we use the same DFS method to traverse the inboard 'O's and convert those to '.'
 *
 * On the final loop, the pending 'O' will be replaced with 'X' and '.' will be replaced with 'O'
 * Time complexity: O(M*N)
 */
void DFS(vector<vector<char> >& board, int i, int j)
{
	board[i][j] = '.';
	vector<int> dir = {-1, 0, 1, 0, -1, 0};
	for(int k = 0; k < 4; k++)
	{
		int r = i + dir[k];
		int c = j + dir[k+1];
		bool inBound = (r >= 0 && r < board.size()) && (c >= 0 && c < board[0].size());
		if (inBound && board[r][c] == 'O')
			DFS(board, r, c);
	}
}

void Solution::solveSurroundedRegion(vector<vector<char> >& board)
{
	for(int i = 0; i < board.size(); i++)
	{
		for(int j = 0; j < board[0].size(); j++)
		{
			bool isBoundary = (i ==0) ||(i == board.size()-1) || (j == 0) || (j == (board[0].size() - 1)) ;
			if (isBoundary && board[i][j] == 'O')
				DFS(board, i, j);
		}
	}

	for(int i = 0; i < board.size(); i++)
	{
		for(int j = 0; j < board[0].size(); j++)
		{
			if (board[i][j] == '.') board[i][j] = 'O';
			else if (board[i][j] == 'O') board[i][j] = 'X';
		}
	}
}

/*
 * Leetcode 236
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 * Example: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output = 3
 *
 * Solution Implemented: Depth First Search. Time Complexity = O(log N)
 */
TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root == nullptr || (root->val == p->val) || (root->val == q->val)) return root;

	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);

	if (left == nullptr) return right;
	else if (right == nullptr) return left;
	else return root;
}

/*
 * Leetcode 329
 * Given an m x n integers matrix, return the length of the longest increasing path in matrix.
 * From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary
 * Example: matrix = [[9,9,4],[6,6,8],[2,1,1]]
 * Output = 4
 * Explanation: The longest increasing path is [1, 2, 6, 9]
 *
 * Solution Implemented: This is graph problem. We take DFS approach with additional step of saving prevCnt of previously recursed calls.
 *
 */
int Solution::longestIncreasingPath(vector<vector<int> >& matrix)
{
	int m = matrix.size(), n = matrix[0].size();
	int len = 0;
	vector<vector<int> > cache(m, vector<int>(n, 0));
	vector<int> dirn = {-1, 0, 1, 0, -1};
	function<int(int, int)> dfs = [&](int r, int c) -> int
	{
		if (cache[r][c]) return cache[r][c];
		for(int i = 0; i < 4; i++)
		{
			int newR = r + dirn[i];
			int newC = c + dirn[i + 1];

			if (newR < 0 || newR >= m || newC < 0 || newC >= n || matrix[newR][newC] <= matrix[r][c]) continue;

			cache[r][c] = max(cache[r][c], dfs(newR, newC));
		}

		return ++cache[r][c];
	};
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			len = 0;
			cout<<"matrix["<<i<<"]["<<j<<"] = "<<matrix[i][j]<<endl;
			len = max(len, dfs(i, j));
		}
	}

	return len;
}

/*
 * Leetcode 315
 * Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].
 * Example: Input = [5,2,6,1]
 * Output = [2,1,1,0]
 * 
 * Solution implemented: Simplest approach to take here is brute force method which will take O(N^2) time complexity.
 * But this approach will not work with larger input set as it takes too much time. 
 * Optimized version of implementing this problem will be to use the concept of Fenwick tree or Binary Index tree.
 * First we identify unique elements in the input and arrange them in ascendign order.
 * Then we use a ranking map to assign ranks for each values of sorted unique input elements. This will be the input for our binary index tree array
 * Each time we traverse through input array backwards, we find the rank of the elements and update the binary index tree. We will also use this tree
 * to query the count.
 * Time complexity of this appraoch : O(N*logN)
 * Space Complexity : O(N)
 */

void updateBTArray(vector<int>& btArray, int index, int delta)
{
	for(; index < btArray.size(); index += (index & -index))
	{
		btArray[index] += delta;
	}
}

int queryBTArray(vector<int>& btArray, int index)
{
	int sum = 0;
	for(; index > 0; index -=(index & -index))
	{
		sum += btArray[index];
	}

	return sum;
}

vector<int> Solution::countSmaller(vector<int>& nums)
{
	vector<int> count(nums.size(), 0);
	set<int> element(nums.begin(), nums.end());
	unordered_map<int, int> ranks;
	vector<int> btArray(element.size() + 1, 0);
	int counter = 0;

	for(auto it: element)
	{
		ranks[it] = ++counter;
	}
	
	for(int i = nums.size()-1; i >=0; i--)
	{
		int rank = ranks[nums[i]];
		updateBTArray(btArray, rank, 1);
		count[i] = queryBTArray(btArray, rank - 1);
	}
	return count;
}

/*
 * LeetCode 124
 * Given the root of a binary tree, return the maximum path sum of any non-empty path
 * Example: root = [-10,9,20,null,null,15,7]
 * Output = 42
 * Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 *
 * Solution Implemented - DFS
 * Time Complexity : O(n), Space Complexity: O(h)  where h is the height of the tree.
 */
int Solution::maxPathSum(TreeNode* head)
{
	int maxSum = INT_MIN;

	function<int(TreeNode*)> DFS = [&](TreeNode* node)
	{
		if(!node) return 0;

		int left = max(0, DFS(node->left));
		int right = max(0, DFS(node->right));

		maxSum = max(maxSum, left + right + node->val);
		return node->val + max(left, right);
	};

	DFS(head);
	return maxSum;
}
