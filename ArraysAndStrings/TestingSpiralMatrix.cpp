#include "Testing.h"

void TestingSpiralMatrix(Solution& op)
{
	vector<vector<int> > ip1 = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
	vector<int> res = op.DisplaySpiralOrder(ip1);
	cout<<"Input matrix: "<<endl;
	for(int i = 0; i < ip1.size(); i++)
	{
		for(auto j : ip1[i])
			cout<<j<<" ";
		cout<<endl;
	}
	cout<<"Result array: ";
	for(auto i : res)
		cout<<i<<" ";
	cout<<endl;

	vector<vector<int> > ip2 = {{1, 2, 3, 4}, {5, 6, 7, 8},{9,10,11,12}};
	res = op.DisplaySpiralOrder(ip2);
	cout<<"Input matrix: "<<endl;
	for(int i = 0; i < ip2.size(); i++)
	{
		for(auto j : ip2[i])
			cout<<j<<" ";
		cout<<endl;
	}
	cout<<"Result array: ";
	for(auto i : res)
		cout<<i<<" ";
	cout<<endl;
}
