#include "Testing.h"

void TestingSortList(Solution& op)
{
	ListNode* list1 = new ListNode(4, new ListNode(2 , new ListNode(1, new ListNode(3, nullptr))));
	cout<<"Input list passed = ";
	op.DisplayList(list1);
	cout<<endl;
	ListNode* res = op.mergeSort(list1);
	cout<<"Resultant list = ";
	op.DisplayList(res);
	cout<<endl;
}
