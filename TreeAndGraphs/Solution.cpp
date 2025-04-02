#include "Solution.h"

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
 *
 *
 *
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
