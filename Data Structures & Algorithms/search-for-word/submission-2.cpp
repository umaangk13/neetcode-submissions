class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        char first = word[0];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == first && f(i,j,n,m,0,board,word)){
                    return true;
                }
            }
        }

        return false;
    }
    bool f(int i, int j, int n, int m, int idx, vector<vector<char>>& board, string &word){
        if(idx == word.size()) return true;
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '#'){
            return false;
        }

        if(board[i][j] == word[idx]){
            char temp = board[i][j];
            board[i][j] = '#';
            bool path = f(i-1,j,n,m,idx+1,board,word) ||
                    f(i,j+1,n,m,idx+1,board,word) ||
                    f(i+1,j,n,m,idx+1,board,word) || 
                    f(i,j-1,n,m,idx+1,board,word);
            board[i][j] = temp;
            return path;
        }
        else{
            return false;
        }
    }
};
