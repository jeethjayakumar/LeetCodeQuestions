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
	cout<<" 10. Sliding Window Maximum\n";
	cout<<" 11. Minimum Window Substring\n";
	cout<<" 12. Find string from prefix\n";
	cout<<" 13. Max Sub-array sum with atmost 1 element deletion\n";
	cout<<" 14. First Unique Character in a string\n";
	cout<<" 15. Valid Anagram\n";
	cout<<" 16. Palindrome Number\n";
	cout<< " 17. Valid Paranthesis\n";
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
