#include "Testing.h"

void TestingValidAnagram(Solution& op)
{
	string s1 = "ADOBECODEBANC", t1 = "ABC";
	cout << "Input string s1 = " << s1 << " , t1 = " << t1 << endl;
	auto out1 = op.isAnagram(s1, t1);
	cout << "Output: " << out1 << endl;

	string s2 = "a", t2 = "a";
	cout << "Input string s2 = " << s2 << ", t2 = " << t2 << endl;
	out1 = op.isAnagram(s2, t2);
	cout << "Output: " << out1 << endl;

	string s3 = "a", t3 = "aa";
	cout << "Input string s3 = " << s3 << ", t3 = " << t3 << endl;
	out1 = op.isAnagram(s3, t3);
	cout << "Output: " << out1 << endl;
}
