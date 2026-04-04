class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> visited(n,0);
        vector<int> curr;
        vector<vector<int>> result;
        f(n,0,curr,visited,nums,result);
        return result;
    }
    void f(int n, int count, vector<int> &curr, vector<int> &visited, vector<int>& nums, vector<vector<int>> &result){
        if(count == n){
            result.push_back(curr);
        }

        for(int i=0;i<n;i++){
            if(visited[i] != 1){
                curr.push_back(nums[i]);
                visited[i] = 1;
                f(n,count+1,curr,visited,nums,result);
                curr.pop_back();
                visited[i] = 0;
            }
        }
    }
};
