#include "Testing.h"

template<class T>
void PrintList(vector<T>& inp)
{
	for(auto item : inp)
		cout<<item<<" ";
}

template<class T>
void PrintInputMatrix(vector<vector<T> >& inp)
{
	for(auto item1 : inp)
	{
		for(auto item2 : item1)
			cout<<item2<<" ";
		cout<<endl;
	}
}

void PrintTree(TreeNode* root, string indent, bool isLeft)
{
	if(!root) return;
	cout<<indent<<"|__"<<root->val<<endl;
	PrintTree(root->right, indent+(isLeft ? "|  ":"  "), true);
	PrintTree(root->left , indent+(isLeft ? "|  ":"  "), false);
}

void Testing::ExecuteOperation(int& choice)
{
	switch(choice)
	{
		case 1:
			TestingWordLadder(op);
			break;
		case 2:
			TestingSurroundedRegion(op);
			break;
		case 3:
			TestingLowestCommonAncestorBTree(op);
			break;
		case 4:
			TestingLongestIncreasingPathMatrix(op);
			break;
		case 5:
			TestingCountOfSmallNumbersAfterSelf(op);
			break;
		case 6:
			TestingBinaryTreeMaximumPathSum(op);
			break;
		case 7:
			TestingBinaryTreePath(op);
			break;
		default:
			cout<<"Invalid choice selected... Aborting...\n";
			break;
	}
}

