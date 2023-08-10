Link : https://leetcode.com/problems/number-of-islands/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
void solve(vector<vector<char>>& grid , int i ,int j,int n ,int m )
{
    if( i < 0 || j < 0 || i >= n || j >= m )
    {
        return ;
    }
    if(grid[i][j]=='0')
    {
        return ;
    }
    grid[i][j]='0';

    solve(grid,i+1,j, n,m );
    solve(grid,i-1,j, n,m );
    solve(grid,i,j+1, n,m );
    solve(grid,i,j-1, n,m );
}

    int numIslands(vector<vector<char>>& grid)
    {
        int count=0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0 ;i<n;i++)
        {
            for(int j = 0 ;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    // recursive call
                    solve(grid,i,j,n,m); 
                    count++;
                }
            }
        }
        return count;       
    }
};
