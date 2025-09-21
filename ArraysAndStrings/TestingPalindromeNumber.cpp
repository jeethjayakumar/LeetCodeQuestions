#include "Testing.h"

void TestingPalindromeNumber(Solution& op)
{
	int x = 121;
	auto res = op.isPalindrome(x);
	cout << "x = " << x << " isPalindrome = " << res << endl;
	x = -121;
	res = op.isPalindrome(x);
	cout << "x = " << x << " isPalindrome = " << res << endl;
	x = 10;
	res = op.isPalindrome(x);
	cout << "x = " << x << " isPalindrome = " << res << endl;
}
