#include "Testing.h"

void printMatrix(vector<vector<int> >& inp)
{
	for(auto l : inp)
	{
		for(auto n : l)
			cout<<n<<" ";
		cout<<endl;
	}
}

void TestingGameOfLife(Solution& op)
{
	vector<vector<int> > inp1 = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
	cout<<"Inp1 : \n";
	printMatrix(inp1);
	op.gameOfLife(inp1);
	cout<<"New Inp1 : \n";
	printMatrix(inp1);
}
