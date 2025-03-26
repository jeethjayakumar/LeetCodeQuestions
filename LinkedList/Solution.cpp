#include "Solution.h"

void Solution::DisplayList(ListNode* head)
{
	ListNode* tmp = head;
	while(tmp != nullptr)
	{
		if (tmp->next != nullptr)
			cout<<tmp->val<<"->";
		else
			cout<<tmp->val;
		tmp = tmp->next;
	}
}

ListNode* Solution::mergeTwoLists(ListNode* left, ListNode* right)
{
	if (!left) return right;
	if (!right) return left;

	if (left->val < right->val)
	{
		left->next = mergeTwoLists(left->next, right);
		return left;
	}
	else
	{
		right->next = mergeTwoLists(left, right->next);
		return right;
	}
}

ListNode* Solution::mergeKListHelper(vector<ListNode*>& inpList, int start, int end)
{
	if (start == end) return inpList[start];
	if (start > end) return nullptr;
	
	int mid = start + (end - start)/2;
	ListNode* left = mergeKListHelper(inpList, start, mid);
	ListNode* right = mergeKListHelper(inpList, mid+1, end);

	return mergeTwoLists(left, right);
}

ListNode* Solution::mergeKLists(vector<ListNode*>& inpList)
{
	if (!inpList.size()) return nullptr;
	
	return mergeKListHelper(inpList, 0, inpList.size() - 1);
}
