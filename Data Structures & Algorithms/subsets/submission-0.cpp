class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        createPow(result, nums, temp, 0);
        return result;
    }
    void createPow(vector<vector<int>>& r, vector<int>& n,vector<int>& t,int i){
        if(i> n.size()-1){
            r.push_back(t);
            return;
        }
        t.push_back(n[i]);
        createPow(r,n,t,i+1);
        t.pop_back();
        createPow(r,n,t,i+1);
    }
};