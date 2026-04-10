class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char,int> mp;
        for(char c : s){
            mp[c]++;
        }

        for(char c : t){
            if(mp.find(c) == mp.end()) return false;
            else{
                mp[c]--;
                if(mp[c] == 0) mp.erase(c);
            }
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<int> visited(strs.size(),0);
        for(int i=0;i<strs.size();i++){
            if(visited[i] != 1){
                visited[i] = 1;
                vector<string> temp;
                temp.push_back(strs[i]);
                for(int j=i+1;j<strs.size();j++){
                    if(visited[j] != 1 && isAnagram(strs[i],strs[j])){
                        temp.push_back(strs[j]);
                        visited[j] = 1;
                    }
                }
                result.push_back(temp);
            }
        }
        return result;
    }
};
