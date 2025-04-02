#include "Testing.h"

int main()
{
	int choice;
	Testing op;
	cout<<"		LEETCODE ARRAYS AND STRINGS EXERCISE     \n";
	cout<<" Choose the exercise to execute and display output : \n";
	cout<<" 1. Product of Array Except Self\n";
	cout<<" 2. Spiral Matrix\n";
	cout<<" 3. 4Sum II\n";
	cout<<" 4. Container with most water\n";
	cout<<" 5. Game of life\n";
	cout<<" 6. First Missing Positive\n";
	cout<<" 7. Longest Consecutive Sequence\n";
	cout<<" 8. Find the duplicate number\n";
	cout<<" 9. Basic Calculator II\n";
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
