#include "Testing.h"

void TestingIntersectionOfList(Solution& op)
{
	ListNode* list1 = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3, nullptr))));
	ListNode* list2 = new ListNode(3, new ListNode(2, new ListNode(1, new ListNode(3, nullptr))));
	cout << "Input listA passed = ";
	op.DisplayList(list1);
	cout << endl;
	cout << "Input listB passed = ";
	op.DisplayList(list2);
	ListNode* res = op.getIntersectionNode(list1, list2);
	cout << "Resultant list = ";
	op.DisplayList(res);
	cout << endl;
}
