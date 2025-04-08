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
		default:
			cout<<"No operations found with that choice!!!\n";
			break;
	}
}
