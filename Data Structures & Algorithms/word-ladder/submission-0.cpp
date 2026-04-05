class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 1. Put all words in a set for O(1) lookups
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        // If the endWord isn't even in the dictionary, no path exists
        if (dict.find(endWord) == dict.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        
        // The sequence length starts at 1 (the beginWord itself)
        int level = 1;

        // 2. Standard BFS
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string curr = q.front(); 
                q.pop();

                // Generate neighbors dynamically by changing one letter at a time
                for (int i = 0; i < curr.length(); i++) {
                    char originalChar = curr[i];
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue; // Skip the same letter
                        
                        curr[i] = c; // Mutate the string
                        
                        // If we found the target word inside our valid dictionary
                        if (curr == endWord && dict.find(curr) != dict.end()) {
                            return level + 1;
                        }
                        
                        // If the mutated word is in the dictionary
                        if (dict.find(curr) != dict.end()) {
                            q.push(curr);
                            dict.erase(curr); // ERASE it to act as our "visited" check
                        }
                    }
                    // Restore the original character for the next loop iteration
                    curr[i] = originalChar;
                }
            }
            level++;
        }
        
        return 0; // No sequence found
    }
};