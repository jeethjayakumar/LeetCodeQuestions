#include "Testing.h"

void TestingBinaryTreePath(Solution& op)
{
	TreeNode* root1 = new TreeNode(1, new TreeNode(2 , nullptr, new TreeNode(5)), new TreeNode(3));
	cout << "\nInput Tree: " << endl;
	PrintTree(root1, "", false);
	vector<string> pathList = op.binaryTreePath(root1);
	cout << "All paths identified for the tree: ";
	PrintList(pathList);

	TreeNode* root2 = new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
	cout << "\nInput Tree: " << endl;
	PrintTree(root2, "", false);
	pathList = op.binaryTreePath(root2);
	cout << "All paths identified for the tree: ";
	PrintList(pathList);
}
