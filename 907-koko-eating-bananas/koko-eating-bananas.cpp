class Solution {
public:
    bool possible(int mid, vector<int>& piles, int h) {
        int hrs = 0;
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] % mid == 0) {
                hrs += piles[i] / mid;
            } else
                hrs += (piles[i] / mid + 1);
            if (hrs > h)
                return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (possible(mid, piles, h)) {
                ans = mid;
                e = mid - 1;
            } else
                s = mid + 1;
        }
        return ans;
    }
};