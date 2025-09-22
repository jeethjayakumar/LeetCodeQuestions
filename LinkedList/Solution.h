#include "NewListNode.h"
#include <vector>

using namespace std;

class Solution
{
	private:
		ListNode* mergeKListHelper(vector<ListNode*>& lists, int start, int end);
		ListNode* mergeTwoLists(ListNode* left, ListNode* right);
		ListNode* getMid(ListNode* head);
		int getListLength(ListNode* head);
	public:
		ListNode* mergeKLists(vector<ListNode*>& lists);
		ListNode* mergeSort(ListNode* head);
		NewListNode* copyRandomList(NewListNode* head);
		ListNode* reverseLinkedList(ListNode* head);
		ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
		void DisplayList(ListNode* head);
};
