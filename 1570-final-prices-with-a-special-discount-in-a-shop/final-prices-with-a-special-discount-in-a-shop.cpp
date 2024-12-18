class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        int n = prices.size();
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() > prices[i]) {
                s.pop();
            }

            int discount = s.empty() ? 0 : s.top();
            ans[i] = prices[i] - discount;
            s.push(prices[i]);
        }

        return ans;
    }
};
