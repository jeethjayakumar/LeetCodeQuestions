/*
 * Given an m x n matrix, return all elements of the matrix in spiral order
 * 
 * Example 1:
 * 	Input: matrix = [[1,2,3],
 * 	                 [4,5,6],
 * 	                 [7,8,9]]
 * 	Output: [1,2,3,6,9,8,7,4,5]
 *
 * Example 2:
 * 	Input: matrix = [[1, 2, 3, 4],
 * 			 [5, 6, 7, 8]
 * 			,[9,10,11,12]]
 * 	Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution
{
	public:
		vector<int> spiralOrder(vector<vector<int> >& matrix)
		{
			cout<<"Inside spiralOrder(matrix)\n";
			int nRow = matrix.size();
			int nCol = matrix[0].size();
			cout<<"nRow = "<<nRow<<"  nCol = "<<nCol<<"\n";
			vector<int> res(nRow*nCol);
			vector<vector<bool> > visited(nRow, vector<bool>(nCol, false));
			
			vector<int> dr = {0, 1, 0, -1}; // Row direction
			vector<int> dc = {1, 0, -1, 0}; // Coln direction

			int i, idx = 0;
			int r = 0, c = 0;

			for (i = 0; i < nRow*nCol; i++)
			{
				res[i] = matrix[r][c];
				cout<<"res["<<i<<"] = "<<res[i]<<"\n";
				visited[r][c] = true;

				int newR = r + dr[idx];
				int newC = c + dc[idx];
				cout<<"idx = "<<idx<<"  newR = "<<newR<<"  newC = "<<newC<<"\n";

				if (0 <= newR && newR < nRow && 
				    0 <= newC && newC < nCol &&
				    ! visited[newR][newC])
				{
					r = newR;
					c = newC;
					cout<<"r = "<<r<<"  c = "<<c<<"\n";
				}
				else
				{
					idx = (idx + 1) % 4;
					r += dr[idx];
					c += dc[idx];
					cout<<"idx = "<<idx<<"  r = "<<r<<"  c = "<<c<<"\n";
				}
			}
			return res;
		}
};

int main()
{
	vector<vector<int> > inp = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	Solution op;
	auto res = op.spiralOrder(inp);
	cout<<"Result = ";
	for(int i = 0; i < res.size(); i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<"\nResult.Size = "<<res.size()<<"\n";
	return 0;
}
