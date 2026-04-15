class Solution {
public:
    vector<vector<int>> result;
    void f(int idx, vector<int> &temp, int n, int k){
        if(k==0){
            result.push_back(temp);
            return;
        }
        if(idx > n) return;
        
        temp.push_back(idx);
        f(idx+1,temp,n,k-1);
        temp.pop_back();
        f(idx+1,temp,n,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        f(1,temp,n,k);
        return result;
    }
};