#include "ListNode.h"
#include <vector>

using namespace std;

class Solution
{
	private:
		ListNode* mergeKListHelper(vector<ListNode*>& lists, int start, int end);
		ListNode* mergeTwoLists(ListNode* left, ListNode* right);
	public:
		ListNode* mergeKLists(vector<ListNode*>& lists);
		void DisplayList(ListNode* head);
};
