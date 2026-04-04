class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        unordered_map<int,string> mp;

        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        
        vector<string> result;
        string curr = "";
        f(0,curr,digits,mp,result);
        return result;
    }
    void f(int idx, string &curr, string &digits, unordered_map<int,string> &mp, vector<string> &result){
        if(idx == digits.size()){
            result.push_back(curr);
            return;
        }
        
        for(char c : mp[digits[idx] - '0']){
            curr.push_back(c);
            f(idx+1,curr,digits,mp,result);
            curr.pop_back();
        }
    }
};
