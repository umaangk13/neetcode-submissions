class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(0,0,n,"",result);
        return result;
    }
    void backtrack(int open, int close, int n, string curr, vector<string>& result) {
        // Base case: We have used n open and n close parentheses
        if (curr.length() == 2 * n) {
            result.push_back(curr);
            return;
        }

        // Choice 1: Add an opening bracket
        // We can do this as long as we haven't hit the limit 'n'
        if (open < n) {
            backtrack(open + 1, close, n, curr + "(", result);
        }

        // Choice 2: Add a closing bracket
        // We can ONLY do this if there is an unmatched open bracket available
        if (close < open) {
            backtrack(open, close + 1, n, curr + ")", result);
        }
    }
};
