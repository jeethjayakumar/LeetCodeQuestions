#include "Solution.h"

class Testing
{
	private:
		Solution op;
	public:
		void ExecuteOperation(int& choice);

};

template<class T> void PrintInputMatrix(vector<vector<T> >& inp);
template<class T> void PrintList(vector<T>& inp);
void PrintTree(TreeNode* root, string indent, bool isLeft);
void TestingWordLadder(Solution& op);
void TestingSurroundedRegion(Solution& op);
void TestingLowestCommonAncestorBTree(Solution& op);
void TestingLongestIncreasingPathMatrix(Solution& op);
void TestingCountOfSmallNumbersAfterSelf(Solution& op);
void TestingBinaryTreeMaximumPathSum(Solution& op);
void TestingBinaryTreePath(Solution& op);
