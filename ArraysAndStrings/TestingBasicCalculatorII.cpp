#include "Testing.h"

void TestingBasicCalculatorII(Solution& op)
{
	string s1 = "3+2*2";
	auto res = op.calculate(s1);
	cout<<s1<<" = "<<res<<endl;
	string s2 = " 3/2 ";
	res = op.calculate(s2);
	cout<<s2<<" = "<<res<<endl;
	string s3 = " 3+5 / 2 ";
	res = op.calculate(s3);
	cout<<s3<<" = "<<res<<endl;
}
