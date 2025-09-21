#include "Testing.h"

void TestingFirstUniqueCharacter(Solution& op)
{
	string s1 = "ADOBECODEBANC";
	cout << "Input string s1 = " << s1 <<endl;
	auto out1 = op.firstUniqChar(s1);
	cout << "Output: " << out1 << endl;

	string s2 = "a";
	cout << "Input string s2 = " << s2<< endl;
	out1 = op.firstUniqChar(s2);
	cout << "Output: " << out1 << endl;

	string s3 = "a";
	cout << "Input string s3 = " << s3 << endl;
	out1 = op.firstUniqChar(s3);
	cout << "Output: " << out1 << endl;
}
