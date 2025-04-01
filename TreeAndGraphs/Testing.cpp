#include "Testing.h"

void Testing::ExecuteOperation(int& choice)
{
	switch(choice)
	{
		case 1:
			TestingWordLadder(op);
			break;
		default:
			cout<<"Invalid choice selected... Aborting...\n";
			break;
	}
}
