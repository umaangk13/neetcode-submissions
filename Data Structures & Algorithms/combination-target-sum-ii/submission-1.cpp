class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, int> counts;
        for (int x : candidates) counts[x]++;

        // Convert map to a list of unique numbers for easy indexing
        vector<int> uniqueNums;
        for (auto const& [val, count] : counts) {
            uniqueNums.push_back(val);
        }

        vector<vector<int>> res;
        vector<int> curr;
        backtrack(0, target, curr, uniqueNums, counts, res);
        return res;
    }

private:
    void backtrack(int idx, int target, vector<int>& curr, 
                   vector<int>& uniqueNums, unordered_map<int, int>& counts, 
                   vector<vector<int>>& res) {
        
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (idx == uniqueNums.size()) return;

        int num = uniqueNums[idx];
        int freq = counts[num];

        // Try taking the current number 'i' times (from 0 up to freq)
        for (int i = 0; i <= freq; ++i) {
            if (i > 0) {
                if (target < num) break; // Pruning: cannot add more of this number
                curr.push_back(num);
                target -= num;
            }
            
            // Move to the NEXT unique number
            backtrack(idx + 1, target, curr, uniqueNums, counts, res);
        }

        // Clean up the 'curr' vector for the parent caller (Backtrack)
        for (int i = 0; i < freq; ++i) {
            if (!curr.empty() && curr.back() == num) {
                curr.pop_back();
            }
        }
    }
};