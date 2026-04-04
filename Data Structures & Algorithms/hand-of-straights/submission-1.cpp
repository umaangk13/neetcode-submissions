class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Base Case: If the total cards aren't divisible by groupSize, 
        // we can't physically form complete groups.
        if (hand.size() % groupSize != 0) return false;

        // Step 1: Frequency Map
        // We use unordered_map for O(1) average lookup/insertion.
        unordered_map<int, int> count;
        for (int num : hand) count[num]++;

        // Step 2: Iterate through every card in the input
        for (int num : hand) {
            int start = num;
            
            // Optimization: Find the "root" of the sequence.
            // If 'start - 1' exists in our map, 'num' isn't the smallest 
            // card in its potential group. We move 'start' backwards 
            // until we find the actual smallest card available in the sequence.
            while (count[start - 1] > 0) {
                start--;
            }

            // Step 3: Process the sequence starting from the smallest card found
            while (start <= num) {
                // While we still have instances of the 'start' card...
                while (count[start] > 0) {
                    // ...try to form a group of 'groupSize' starting from 'start'
                    for (int i = start; i < start + groupSize; i++) {
                        // If any consecutive card needed for the group is missing,
                        // it's impossible to satisfy the condition.
                        if (count[i] == 0) return false;
                        
                        // Use up one instance of the card
                        count[i]--;
                    }
                }
                // Move to the next potential starting number in the sequence
                start++;
            }
        }
        
        // If we successfully exhausted all cards into valid groups
        return true;
    }
};
