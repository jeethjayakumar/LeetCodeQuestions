#include "Testing.h"

void TestingBinaryTreeMaximumPathSum(Solution& op)
{
	TreeNode* root1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
	cout<<"\nInput Tree: "<<endl;
	PrintTree(root1, "", false);
	auto maxSum = op.maxPathSum(root1);
	cout<<"Max Path Sum for Tree 1 = "<<maxSum<<endl;

	TreeNode* root2 = new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
	cout<<"\nInput Tree: "<<endl;
	PrintTree(root2, "", false);
	maxSum = op.maxPathSum(root2);
	cout<<"Max Path Sum for Tree 2 = "<<maxSum<<endl;


}
