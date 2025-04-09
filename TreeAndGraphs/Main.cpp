#include "Testing.h"

int main()
{
	Testing test;
	int choice;

	cout<<"			LEETCODE EXERCISE - TREES AND GRAPHS		\n";
	cout<<" Enter your choice of exercise to execute: \n";
	cout<<"1. Word Ladder \n";
	cout<<"2. Surrounded Region \n";
	cout<<"3. Lowest Common Ancestor of a Binary Tree \n";
	cout<<"4. Longest Increasing Path in a Matrix \n";
	cout<<"5. Count of Smaller Numbers after self \n";
	cout<<"6. Binary Ttree Maximum Path Sum \n";
	cout<<"0. Exit \n";
	cout<<" Enter your choice: ";
	cin>>choice;

	if(choice == 0)
	{
		cout<<"Thanking you for using this executable for testing... \n";
		return 0;
	}

	test.ExecuteOperation(choice);

	return 0;
}
