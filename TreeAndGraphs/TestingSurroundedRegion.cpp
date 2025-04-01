#include "Testing.h"

void PrintMatrix(vector<vector<char> >& inp)
{
	for(auto item1 : inp)
	{
		for(auto item2 : item1)
			cout<<item2<<" ";
		cout<<endl;
	}
}

void TestingSurroundedRegion(Solution& op)
{
	vector<vector<char> > board1 = {{'X','X','X','X'}, {'X','O','O','X'}, {'X','X','O','X'}, {'X','O','X','X'}};
	cout<<"Current Board: \n";
	PrintMatrix(board1);
	//PrintInputMatrix<char>(board1);
	cout<<endl;
	op.solveSurroundedRegion(board1);
	cout<<"New Board: \n";
	PrintMatrix(board1);
	//PrintInputMatrix<char>(board1);
	cout<<endl;
	
	vector<vector<char> > board2 = {{'O','X','X','O','X'},{'X','O','O','X','O'},{'X','O','X','O','X'},{'O','X','O','O','O'},{'X','X','O','X','O'}};
	cout<<"Current Board: \n";
	PrintMatrix(board2);
	cout<<endl;
	op.solveSurroundedRegion(board2);
	cout<<"New Board: \n";
	PrintMatrix(board2);
	cout<<endl;

	vector<vector<char> > board3 = {{'X','O','X'},{'X','O','X'},{'X','O','X'}};
	cout<<"Current Board: \n";
	PrintMatrix(board3);
	cout<<endl;
	op.solveSurroundedRegion(board3);
	cout<<"New Board: \n";
	PrintMatrix(board3);
	cout<<endl;
}
