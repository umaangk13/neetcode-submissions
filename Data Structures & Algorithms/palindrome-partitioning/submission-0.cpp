class Solution {
public:
    bool palindrome(int left, int right, string &s){
        int l=left,r=right;
        while(l<=r){
            if(s[l] != s[r]){
                return false;
            }
            l++; r--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> result;
        vector<string> curr;
        f(0,s,curr,result);
        return result;
    }
    void f(int idx, string &s, vector<string> &curr, vector<vector<string>> &result){
        if(idx == s.length()){
            result.push_back(curr);
            return;
        }

        // string temp = "";
        int left = idx;
        for(int i=idx;i<s.length();i++){
            if(palindrome(left,i,s)){
                curr.push_back(s.substr(left,i-left+1));
                f(i+1,s,curr,result);
                curr.pop_back();
            }
        }
    }
};
