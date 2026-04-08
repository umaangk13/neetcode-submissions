class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> inDeg;
        
        // FIX 1 & 3: Initialize inDeg for ALL unique characters to 0
        for (const string& word : words) {
            for (char c : word) {
                inDeg[c] = 0;
            }
        }
        
        // Build the graph
        for (int i = 0; i < words.size() - 1; i++) {
            string& s1 = words[i];
            string& s2 = words[i+1];
            int len = min(s1.length(), s2.length());
            
            // FIX 2: Check for invalid prefix ordering
            if (s1.length() > s2.length() && s1.substr(0, len) == s2) {
                return ""; 
            }
            
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j]].push_back(s2[j]);
                    inDeg[s2[j]]++;
                    break;
                }
            }
        }
        
        // Kahn's Algorithm
        queue<char> q;
        for (auto& it : inDeg) {
            if (it.second == 0) {
                q.push(it.first);
            }
        }
        
        string res = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            res += curr;
            
            for (char neighbor : adj[curr]) {
                inDeg[neighbor]--;
                if (inDeg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // FIX 4: Cycle detection
        if (res.length() != inDeg.size()) {
            return "";
        }
        
        return res;
    }
};