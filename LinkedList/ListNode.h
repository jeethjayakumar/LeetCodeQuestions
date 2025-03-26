#include <iostream>

class ListNode
{
	public:
		int val;
		ListNode* next;
		ListNode(int n)
		{
			val = n;
			next = nullptr;
		}

		ListNode(int n, ListNode* nxt)
		{
			val = n;
			next = nxt;
		}
};
