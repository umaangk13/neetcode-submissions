class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        int curr=0, n_3 = 0, n_2 = 1, n_1 = 1;
        for(int i=3;i<=n;i++){
            curr = n_3+n_2+n_1;
            n_3 = n_2;
            n_2 = n_1;
            n_1 = curr;
        }
        return curr;
    }
};