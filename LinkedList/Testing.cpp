#include "Testing.h"

void Testing::ExecuteOperation(int& choice)
{
	Solution op;
	switch(choice)
	{
		case 1:
			TestingMergeKSortedList(op);
			break;
		default:
			cout<<"No operations found with that choice!!!\n";
			break;
	}
}
