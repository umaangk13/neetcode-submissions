class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0) return false;

        // Step 1: Count the frequency of each card.
        // std::map automatically sorts the keys in ascending order.
        map<int, int> cardCounts;
        for (int card : hand) {
            cardCounts[card]++;
        }

        // Step 2: Try to form groups
        for (auto it : cardCounts) {
            int startCard = it.first;
            int count = it.second;

            // If we have some of these cards left, we MUST start a group with it.
            // Why? Because it's currently the smallest available card in the map.
            if (count > 0) {
                // Try to form 'count' number of groups starting with 'startCard'
                for (int i = 0; i < groupSize; i++) {
                    // If we don't have enough of the required consecutive card, we fail.
                    if (cardCounts[startCard + i] < count) {
                        return false;
                    }
                    // Deduct the cards we just used to form the groups
                    cardCounts[startCard + i] -= count;
                }
            }
        }

        return true;
    }
};
