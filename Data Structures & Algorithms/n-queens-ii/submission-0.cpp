class Solution {
public:
    int f(int i, int n, vector<int> &col, vector<int> &negDiag, vector<int> &posDiag){
        if(i>=n) return 1;

        int ways=0;
        for(int j=0;j<n;j++){
            if(col[j] != 1 && negDiag[i-j+n] != 1 && posDiag[i+j] != 1){
                col[j] = 1;
                negDiag[i-j+n] = 1;
                posDiag[i+j] = 1;
                ways += f(i+1,n,col,negDiag,posDiag);
                col[j] = 0;
                negDiag[i-j+n] = 0;
                posDiag[i+j] = 0;
            }
        }
        return ways;
    }
    int totalNQueens(int n) {
        vector<int> col(n,0);
        vector<int> negDiag(2*n,0);
        vector<int> posDiag(2*n,0);
        return f(0,n,col,negDiag,posDiag);
    }
};