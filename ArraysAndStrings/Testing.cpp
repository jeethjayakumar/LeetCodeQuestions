#include "Testing.h"

void Testing::ExecuteOperation(int& choice)
{
	switch(choice)
	{
		case 1:
			TestingProductOfArrayExceptSelf(op);
			break;
		case 2:
			TestingSpiralMatrix(op);
			break;
		case 3:
			Testing4SumII(op);
			break;
		default:
			cout<<"No operations found with that choice!!!\n";
			break;
	}
}
