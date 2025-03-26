/*
 *
 *
 *
 */
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

class Solution
{
	public:
		int calculate(string& s)
		{
			stack<int> numStack;
			int result = 0, currentValue = 0, sSize = s.size();
			char operSign = '+';
			for(int i = 0; i < sSize; i++)
			{
			//	cout<<"s["<<i<<"] = "<<s[i]<<endl;
				if (isdigit(s[i]))
				{
					currentValue = (currentValue * 10) + (s[i] - '0');
			//		cout<<"currentValue = "<<currentValue<<endl;
				}
				if (i == sSize - 1 || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
				{
					auto topVal = 0;
					if (!numStack.empty()) topVal = numStack.top();
					switch(operSign)
					{
						case '+':
							numStack.push(currentValue);
							break;
						case '-':
							numStack.push(-currentValue);
							break;
						case '*':
							numStack.pop();
							numStack.push(topVal * currentValue);
							break;
						case '/':
							numStack.pop();
							numStack.push(topVal / currentValue);
							break;
					}
					operSign = s[i];
					currentValue = 0;
				}

			}
			
			while (!numStack.empty())
			{
				result += numStack.top();
				numStack.pop();
			}
			return result;
		};
};

int main()
{
	string inp1 = "3+2*2";
	string inp2 = " 3/2 ";
	string inp3 = " 3+5 / 2 ";

	Solution op;
	auto res = op.calculate(inp1);
	cout<<inp1<<" = "<<res<<endl;
	res = op.calculate(inp2);
	cout<<inp2<<" = "<<res<<endl;
	res = op.calculate(inp3);
	cout<<inp3<<" = "<<res<<endl;

	return 0;
}
