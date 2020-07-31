#include<iostream>
using namespace std;

template <class T>
class TreeNode
{
	T val;
	TreeNode* right;
	TreeNode* left;
public:
	TreeNode(T val)
	{
		this->val = val;
		right = NULL;
		left = NULL;
	}

	~TreeNode(){}
};
