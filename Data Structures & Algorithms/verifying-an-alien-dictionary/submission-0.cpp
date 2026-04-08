class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // Step 1: Map each character to its "rank" in the alien alphabet
        int rank[26];
        for (int i = 0; i < order.length(); i++) {
            rank[order[i] - 'a'] = i;
        }

        // Step 2: Compare each word with the next word
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            
            bool foundDifference = false;
            
            // Compare character by character up to the length of the shorter word
            for (int j = 0; j < min(w1.length(), w2.length()); j++) {
                if (w1[j] != w2[j]) {
                    // If w1's character has a higher rank than w2's, it's out of order
                    if (rank[w1[j] - 'a'] > rank[w2[j] - 'a']) {
                        return false;
                    }
                    foundDifference = true;
                    break; // We found the first difference, and it's sorted, so stop checking this pair
                }
            }
            
            // Step 3: Handle the prefix edge case
            // If we didn't find any different characters, but w1 is longer than w2 
            // (e.g., w1 = "apple", w2 = "app"), then it's out of order.
            if (!foundDifference && w1.length() > w2.length()) {
                return false;
            }
        }
        
        return true;
    }
};