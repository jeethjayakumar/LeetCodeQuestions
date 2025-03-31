#include "Testing.h"

void PrintInputList(vector<int>& inp)
{
	for(auto n : inp)
		cout<<n<<" ";
}

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
		case 4:
			TestingContainerWithMostWater(op);
			break;
		case 5:
			TestingGameOfLife(op);
			break;
		case 6:
			TestingFirstMissingPositive(op);
			break;
		case 7:
			TestingLongestConsecutiveSequence(op);
			break;
		case 8:
			TestingFindTheDuplicateNumber(op);
			break;
		default:
			cout<<"No operations found with that choice!!!\n";
			break;
	}
}
