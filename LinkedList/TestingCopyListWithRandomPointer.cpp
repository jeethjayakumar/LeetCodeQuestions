#include "Testing.h"

void TestingCopyListWithRandomPointer(Solution& op)
{
	NewListNode* head = new NewListNode(7, nullptr, new NewListNode(13, 0, new NewListNode(11, 4, new NewListNode(10, 2, new NewListNode(1, 0, nullptr)))));
	NewListNode* newHead = op.copyRandomList(head);
}
