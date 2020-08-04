/*
 	Leet Code 200:
 		Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
		An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
		You may assume all four edges of the grid are all surrounded by water.
 */
#include <vector>
#include <iostream>

using namespace std;

// Concept copied from LeetCode Discussion section as my approach didn't worked!!!
// Needed rework on my approach and then will be updating on this code!!!
void dfs(vector<vector<int> > &mark, vector<vector<char> > &grid, int x, int y)
{
	mark[x][y] = 0;
	static const int dx[] = {-1,1,0,0};
	static const int dy[] = {0,0,-1,1};
	int i, j, nx, ny;
	for (i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx< 0 || nx >= mark.size() ||
		    ny <0 || ny >= mark.size())
			continue;
		if (mark[nx][ny] == 0 && grid[nx][ny] == '1')
			dfs(mark, grid, nx, ny);
	}
}

int numIsland(vector<vector<char> > &grid)
{
	int island_num = 0;
	int i,j;
	vector<vector<int> > mark;
	vector<int> temp;
	for (i = 0; i < grid.size(); i++)
	{
		for (j = 0; j < grid[i].size(); j++)
			temp.push_back(0);
		mark.push_back(temp);
		temp.clear();
	}

	for (i = 0; i < grid.size(); i++)
	{
		for (j = 0; j < grid[i].size(); j++)
		{
			if (mark[i][j] == 0 && grid[i][j] == '1')
			{
				dfs(mark, grid, i, j);
				island_num ++;
			}
		}
	} 

	return island_num;
}

int main()
{
	vector<vector<char> > grid;
        vector<char> temp;	
	
	temp.push_back('1');
	temp.push_back('1');
	temp.push_back('1');
	temp.push_back('1');
	temp.push_back('0');
	grid.push_back(temp);
	temp.clear();

	temp.push_back('1');
	temp.push_back('1');
	temp.push_back('0');
	temp.push_back('1');
	temp.push_back('0');
	grid.push_back(temp);
	temp.clear();

	temp.push_back('1');
	temp.push_back('1');
	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('0');
	grid.push_back(temp);
	temp.clear();
	
	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('0');
	temp.push_back('0');
	grid.push_back(temp);
	temp.clear();
	
	cout<<"Number of Islands in test data :"<<numIsland(grid)<<endl;
	return 0;
}
