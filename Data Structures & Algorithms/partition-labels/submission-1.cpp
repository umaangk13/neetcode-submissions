class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int,int>> freq(26,{-1,-1}); // [startIdx,endIdx]
        vector<int> result;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(freq[s[i]-'a'].first == -1){
                freq[s[i]-'a'].first = i;
                freq[s[i]-'a'].second = i;
            }
            else{
                freq[s[i]-'a'].second = i;
            }
        }

        int l=0,r=0;
        while(l<n){
            int len=0;
            while(l<=r){
                r = max(r,freq[s[l]-'a'].second);
                len++;
                l++;
            }
            result.push_back(len);
            len=0;
            r=l;
        }
        return result;
    }
};
