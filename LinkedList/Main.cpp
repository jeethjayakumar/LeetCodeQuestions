#include "Testing.h"

int main()
{
	Testing op;
	int choice;
	
	cout<<"		LEETCODE LINKED LIST EXERCISE		\n";
	cout<<" Choose the exercise to execute and display outpur : \n";
	cout<<" 1. Merge K Sorted Lists \n";
	cout<<" 0. Exit\n";
	cout<<" Enter your choice: ";
	cin>>choice;
	
	if (choice == 0)
	{
		cout<<"Thank you for using this code!!!\n";
		return 0;
	}

	op.ExecuteOperation(choice);

	return 0;
}
