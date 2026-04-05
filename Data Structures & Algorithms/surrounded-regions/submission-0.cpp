class Solution {
public:
    int n=0,m=0;
    void solve(vector<vector<char>>& board) {
        n = board.size(); m = board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(board[i][0] == 'O'){
                board[i][0] = '#';
                q.push({i,0});
            }
            if(board[i][m-1] == 'O'){
                board[i][m-1] = '#';
                q.push({i,m-1});
            }
        }
        for(int j=0;j<m;j++){
            if(board[0][j] == 'O'){
                board[0][j] = '#';
                q.push({0,j});
            }
            if(board[n-1][j] == 'O'){
                board[n-1][j] = '#';
                q.push({n-1,j});
            }
        }
        
        int Row[] = {0,-1,0,1};
        int Col[] = {-1,0,1,0};

        while(!q.empty()){
            auto [r,c] = q.front(); q.pop();
            for(int k=0;k<4;k++){
                int nr = r + Row[k];
                int nc = c + Col[k];
                if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc] == 'O'){
                    board[nr][nc] = '#';
                    q.push({nr,nc});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
