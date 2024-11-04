class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int k) {
        int n = hand.size();
        if (n % k != 0) return false;

        unordered_map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }

        vector<int> keys;
        for (const auto& pair : freq) {
            keys.push_back(pair.first);
        }
        sort(keys.begin(), keys.end());

        for (int i = 0; i < keys.size(); i++) {
            int currentCard = keys[i];
            if (freq[currentCard] > 0) {
                int count = freq[currentCard];
                for (int j = 0; j < k; j++) {
                    if (freq[currentCard + j] < count) {
                        return false;
                    }
                    freq[currentCard + j] -= count;
                }
            }
        }

        return true;
    }
};