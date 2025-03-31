#include "Testing.h"

void Testing::ExecuteOperation(int& choice)
{
	switch(choice)
	{
		case 1:
			cout<<"Word Ladder executed\n";
			break;
		default:
			cout<<"Invalid choice selected... Aborting...\n";
			break;
	}
}
