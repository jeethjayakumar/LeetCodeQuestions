#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

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
		vector<int> findKLargestElements(vector<int>& inp, int& k);
		vector<string> FindStringsForPrefix(vector<string>& words, const string& prefix);
		int maximumSum(vector<int>& nums);
		int firstUniqChar(string& s);
		bool isAnagram(string& s, string& t);
		bool isPalindrome(int& x);
};

// This Trie Structure is defined for FindStringsForPrefix Solution. Not made generic to others
struct TrieNode
{
	unordered_map<char, TrieNode* > children;
	bool isWord = false;
};

class Trie
{
	TrieNode* root;
public:
	Trie()
	{
		root = new TrieNode();
	}

	~Trie()
	{
		delete root;
	}

	void insert(const string& word);
	void dfs(TrieNode* node, const string& prefix, vector<string>& res);
	vector<string> startsWith(const string& prefix);
};