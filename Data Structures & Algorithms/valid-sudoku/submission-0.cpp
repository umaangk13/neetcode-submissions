class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> threeBythree(9);
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char val = board[i][j];
                if(val == '.') continue;
                int box = (i/3)*3 + (j/3);
                if(threeBythree[box].count(val) > 0
                    || row[i].count(val)>0
                    || col[j].count(val)>0) {return false;}
                threeBythree[box].insert(val);
                row[i].insert(val);
                col[j].insert(val);
            }
        }
        return true;
    }
};
