Link : https://leetcode.com/problems/surrounded-regions/?envType=study-plan-v2&envId=top-interview-150

class Solution {
void dfs(vector<vector<char>>& board, int x, int y, int m, int n){
    if(x<0 || x>=m || y<0 || y>=n || board[x][y]!='O') return;
    board[x][y]='#';
    dfs(board, x+1, y, m, n);
    dfs(board, x-1, y, m, n);
    dfs(board, x, y+1, m, n);
    dfs(board, x, y-1, m, n);
}
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n=board[0].size();
        if(m==0) return;
        for(int i=0;i<m;i++){
            //left boundary
            if(board[i][0]=='O') dfs(board, i, 0, m, n);
            //right boundary
            if(board[i][n-1]=='O') dfs(board, i, n-1, m, n);
        }

        for(int i=0;i<n;i++){
            if(board[0][i]=='O') dfs(board, 0, i, m, n);
            if(board[m-1][i]=='O') dfs(board, m-1, i, m, n);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
};
