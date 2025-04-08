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

/*
 * Leetcode 23
 * Given an array of k linked-lists lists where each linked-list is sorted in ascending order, Merge all the linked-lists into one sorted linked-list and return it.
 * Example 1:
 * Input: lists = [[1,4,5],[1,3,4],[2,6]]
 * Output: [1,1,2,3,4,4,5,6]
 *
 * Solution Implemented: Approach taken is similar to merge sort and multiple recursion. MergeSort approach was used to traverse through the list of linked list.
 * This will avoid going through list in multiple loops thereby avoiding O(n^2) time complexity.
 *
 */
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

/*
 * Leetcode 148
 *
 */
ListNode* Solution::getMid(ListNode* head)
{
	ListNode* slow = head;
	ListNode* fast = head->next;

	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

ListNode* Solution::mergeSort(ListNode* head)
{
	if (!head || !head->next) return head;

	ListNode* mid = getMid(head);
	ListNode* left = head;
	ListNode* right = mid->next;
	mid->next = nullptr;

	left = mergeSort(left);
	right = mergeSort(right);

	return mergeTwoLists(left, right);
}

/*
 * Leetcode 138
 *
 */
NewListNode* Solution::copyRandomList(NewListNode* head)
{
	if (!head) return nullptr;
	
	NewListNode* curr = head;
	while(curr != nullptr)
	{
		NewListNode* newNode = new NewListNode(curr->val);
		newNode->next = curr->next;
		curr->next = newNode;
		curr = (NewListNode*)newNode->next;
	}

	curr = head;
	while(curr != nullptr)
	{
		if (curr->random != nullptr)
			(NewListNode*)(curr->next)->random = (NewListNode*)curr->random->next;
		curr = (NewListNode*)curr->next->next;
	}

	NewListNode* newHead = (NewListNode*)head->next;
	curr = head;
	NewListNode* newCurr;
	while(curr != nullptr)
	{
		newCurr = (NewListNode*)curr->next;
		curr->next = (NewListNode*)newCurr->next;
		if (curr->next != nullptr)
			newCurr->next = (NewListNode*)curr->next->next;
		else
			newCurr->next = nullptr;
		curr = (NewListNode*)curr->next;
	}
	return newHead;
}
