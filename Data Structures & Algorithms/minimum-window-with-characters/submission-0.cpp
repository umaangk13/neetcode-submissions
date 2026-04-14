class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";
        
        unordered_map<char, int> freqT;
        for(char c : t) freqT[c]++;
        
        int unmatched = t.length();
        int left = 0, right = 0;
        
        int minLen = INT_MAX;
        int startIdx = 0; // Better to store the start index than calculating substrings on the fly
        
        while(right < s.length()) {
            // EXPAND THE WINDOW
            if(freqT.find(s[right]) != freqT.end()) {
                // If we actually needed this character, decrease unmatched
                if(freqT[s[right]] > 0) {
                    unmatched--;
                }
                // Always decrement the map. It can go negative to represent excess characters!
                freqT[s[right]]--; 
            }
            
            // SHRINK THE WINDOW
            // Once unmatched is 0, we have a valid window. Let's make it as small as possible.
            while(unmatched == 0) {
                
                // Update the minimum length inside the shrinking loop
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }
                
                // Remove the left character from the window as we shrink
                if(freqT.find(s[left]) != freqT.end()) {
                    freqT[s[left]]++; // Restore it to the map
                    
                    // If the map value becomes > 0, it means we lost a character we desperately needed
                    if(freqT[s[left]] > 0) {
                        unmatched++;
                    }
                }
                left++;
            }
            right++;
        }
        
        // If minLen is still INT_MAX, we never found a valid window
        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};