#include "Testing.h"

void TestingValidParanthesis(Solution& op)
{
	string s1 = "()";
	cout << "Input string s1 = " << s1 << endl;
	auto out1 = op.isValidParanthesis(s1);
	cout << "Output: " << out1 << endl;

	string s2 = "(){[]}";
	cout << "Input string s2 = " << s2 << endl;
	out1 = op.isValidParanthesis(s2);
	cout << "Output: " << out1 << endl;

	string s3 = "([)]";
	cout << "Input string s3 = " << s3 << endl;
	out1 = op.isValidParanthesis(s3);
	cout << "Output: " << out1 << endl;
}
