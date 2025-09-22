#include "Testing.h"

void Testing::ExecuteOperation(int& choice)
{
	Solution op;
	switch(choice)
	{
		case 1:
			TestingMergeKSortedList(op);
			break;
		case 2:
			TestingSortList(op);
			break;
		case 3:
			TestingCopyListWithRandomPointer(op);
			break;
		case 4:
			TestingReverseLinkedList(op);
			break;
		case 5:
			TestingIntersectionOfList(op);
			break;
		default:
			cout<<"No operations found with that choice!!!\n";
			break;
	}
}
