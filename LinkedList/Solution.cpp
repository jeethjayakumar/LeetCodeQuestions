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
		curr = static_cast<NewListNode*>(newNode->next);
	}

	curr = head;
	while(curr != nullptr)
	{
		if (curr->random != nullptr)
			static_cast<NewListNode*>(curr->next)->random = static_cast<NewListNode*>(curr->random->next);
		curr = static_cast<NewListNode*>(curr->next->next);
	}

	NewListNode* newHead = (NewListNode*)head->next;
	curr = head;
	NewListNode* newCurr;
	while(curr != nullptr)
	{
		newCurr = static_cast<NewListNode*>(curr->next);
		curr->next = newCurr->next;
		if (curr->next != nullptr)
			newCurr->next = static_cast<NewListNode*>(curr->next->next);
		else
			newCurr->next = nullptr;
		curr = static_cast<NewListNode*>(curr->next);
	}
	return newHead;
}

/*
 * LeetCode 206 - Reverse a Linked List
 * 
 * Time Complexity O(n) Space Complexity O(1)
 */
ListNode* Solution::reverseLinkedList(ListNode* head)
{
	ListNode* curr = head, *prev = nullptr, *nxt = nullptr;
	while (curr != nullptr)
	{
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}
	head = prev;
	return head;
}

/*
 * LeetCode 160 - Intersection of Two linked list
 *
 */
int Solution::getListLength(ListNode* head)
{
	ListNode* curr = head;
	int len = 0;

	while (curr != nullptr)
	{
		len++;
		curr = curr->next;
	}
	return len;
}

ListNode* Solution::getIntersectionNode(ListNode* headA, ListNode* headB)
{
	ListNode* currA = headA, * currB = headB;
	int diff = 0;
	int lenA = getListLength(headA);
	int lenB = getListLength(headB);
	
	if (lenA < lenB)
	{
		diff = lenB - lenA;
		while (diff != 0)
		{
			currB = currB->next;
			diff--;
		}
	}
	else
	{
		diff = lenA - lenB;
		while (diff != 0)
		{
			currA = currA->next;
			diff--;
		}
	}

	while (currA != nullptr && currB != nullptr)
	{
		if (currA == currB) return currA;
		currA = currA->next;
		currB = currB->next;
	}
	return nullptr;
}