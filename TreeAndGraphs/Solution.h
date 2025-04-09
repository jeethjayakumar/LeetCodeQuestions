#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include "TreeNode.h"

using namespace std;

class Solution
{
	private:
		int extendQueue(unordered_map<string, int>& CurrDir, unordered_map<string, int>& OppDir, queue<string>& CurrQueue, unordered_set<string>& words);
	public:
		int ladderLength(string beginWord, string endWord, vector<string>& wordList);
		void solveSurroundedRegion(vector<vector<char> >& board);
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
		int longestIncreasingPath(vector<vector<int> >& matrix);
		vector<int> countSmaller(vector<int>& nums);
		int maxPathSum(TreeNode* root);
};
