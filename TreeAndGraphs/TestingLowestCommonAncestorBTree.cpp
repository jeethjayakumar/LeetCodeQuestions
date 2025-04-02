#include "Testing.h"

void PrintTree(TreeNode* root, string indent, bool isLeft)
{
	if(!root) return;
	cout<<indent<<"|__"<<root->val<<endl;
	PrintTree(root->right, indent+(isLeft ? "|  ":"  "), true);
	PrintTree(root->left , indent+(isLeft ? "|  ":"  "), false);
}

void TestingLowestCommonAncestorBTree(Solution& op)
{
	TreeNode* root1 = new TreeNode(3, new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4))), new TreeNode(1, new TreeNode(0), new TreeNode(8)));
	TreeNode* p1 = new TreeNode(5);
	TreeNode* q1 = new TreeNode(1);
	cout<<"Input Tree: "<<endl;
	PrintTree(root1, "", false);
	cout<<"P node : "<<p1->val<<endl;
	cout<<"Q node : "<<q1->val<<endl;
	TreeNode* result = op.lowestCommonAncestor(root1, p1, q1);
	cout<<"Lowest Common Ancestor: "<<result->val<<endl;
	cout<<endl;

	TreeNode* p2 = new TreeNode(7);
	TreeNode* q2 = new TreeNode(4);
	cout<<"Input Tree: "<<endl;
	PrintTree(root1, "", false);
	cout<<"P node : "<<p2->val<<endl;
	cout<<"Q node : "<<q2->val<<endl;
	result = op.lowestCommonAncestor(root1, p2, q2);
	cout<<"Lowest Common Ancestor: "<<result->val<<endl;
}
