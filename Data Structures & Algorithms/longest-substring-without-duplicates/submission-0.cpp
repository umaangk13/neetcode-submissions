class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        unordered_map<char,int> mp;
        int result=0;
        while(l < s.length() && r < s.length()){
            if(mp.find(s[r]) == mp.end()){
                mp[s[r]] = 1;
                r++;
                result = max(result,r-l);
            }
            else{
                while(l<=r && s[l] != s[r]){
                    mp.erase(s[l]);
                    l++;
                }
                l++;
                r++;
            }
        }
        return result;
    }
};