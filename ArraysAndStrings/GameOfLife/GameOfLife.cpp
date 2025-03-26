/*
 * According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
 * The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0).
 * Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
 * 	1. Any live cell with fewer than two live neighbors dies as if caused by under-population.
 * 	2. Any live cell with two or three live neighbors lives on to the next generation.
 * 	3. Any live cell with more than three live neighbors dies, as if by over-population.
 *	4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 * The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.
 * Given the current state of the board, update the board to reflect its next state.
 *
 * Example 1:
 * Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
 * Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
 *
 * Example 2:
 * Input: board = [[1,1],[1,0]]
 * Output: [[1,1],[1,1]]
 */
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution
{
	public:
		void gameOfLife(vector<vector<int> >& board)
		{
			int nRow = board.size(), nCol = board[0].size();
			vector<int> nbRow = {-1, -1, 0, 1, 1,  1,  0};
			vector<int> nbCol = { 0,  1, 1, 1, 0, -1, -1};
			vector<vector<int> > output = board;
			int i = 0; int j = 0;
			int defLiveConditionCount1 = 2;
			int defLiveConditionCount2 = 3;
			for(i = 0;i < nRow; i++)
			{
				cout<<"Current i = "<<i<<endl;
				for(j = 0;j < nCol; j++)
				{
					cout<<"Current board position: i = "<<i<<" j = "<<j<<endl;
					int count = 0;
					for(int k = 0; k < nbRow.size(); k++)
					{
						int neighborRow = i + nbRow[k];
						int neighborCol = j + nbCol[k];

						if (neighborRow >= 0 && neighborRow < nRow &&
						    neighborCol >= 0 && neighborCol < nCol)
						{
							if (board[neighborRow][neighborCol] == 1)
								count ++;
						}

					}
					cout<<"Board value = "<<board[i][j]<<"  Live neighbor population = "<<count<<endl;
					if (!board[i][j])
					{
						if (count == defLiveConditionCount2)
							output[i][j] = 1;
						else
							output[i][j] = 0;
					}
					else
					{
						if (count == defLiveConditionCount1 || count == defLiveConditionCount2)
							output[i][j] = 1;
						else
							output[i][j] = 0;
					}
					cout<<"Output["<<i<<"]["<<j<<"] = "<<output[i][j]<<endl;
				}
			}

			board = output;
		}

		void gameOfLifeSameBoardUpdate(vector<vector<int> >& board)
		{
			int nRow = board.size(), nCol = board[0].size();
			vector<int> ndRow = {-1, -1, -1, 0, 1, 1,  1,  0};
			vector<int> ndCol = {-1,  0,  1, 1, 1, 0, -1, -1};
			vector<vector<bool> > changedVal(nRow, vector<bool>(nCol, false));
			for(int i = 0; i < nRow; i ++)
			{
				for(int j = 0; j < nCol; j++)
				{
					int count = 0;
					for(int k = 0; k < ndRow.size(); k++)
					{
						int nbRow = i + ndRow[k];
						int nbCol = j + ndCol[k];
						if (nbRow >=0 && nbRow < nRow &&
						    nbCol >=0 && nbCol < nCol)
						{
							if (board[nbRow][nbCol] == 1 && !changedVal[nbRow][nbCol])
								count++;
							if (!board[nbRow][nbCol] && changedVal[nbRow][nbCol])
								count++;
						}
					}
					cout<<"Current Position: "<<i<<"  "<<j<<"  board value = "<<board[i][j]<<"  neighbor count = "<<count<<endl;
					if (board[i][j] == 0)
					{
						if (count == 3)
						{
							board[i][j] = 1;
							changedVal[i][j] = true;
						}
					}
					else
					{
						if (count < 2 || count > 3)
						{
							board[i][j] = 0;
							changedVal[i][j] = true;
						}
					}
				}
			}
		}
};

int main()
{
	vector<vector<int> > board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
	Solution op;

	op.gameOfLifeSameBoardUpdate(board);
	cout<<"Next transition: \n";
	for(auto b : board)
	{
		for(auto c : b)
		{
			cout<<c<<" ";
		}
		cout<<endl;
	}
}
