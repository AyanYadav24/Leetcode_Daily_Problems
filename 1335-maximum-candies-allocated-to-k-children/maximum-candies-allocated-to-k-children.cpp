class Solution {
private : 
     bool solve(long long mid,vector<int>& candies, long long k) {
        long long c = 0;
        for (int &i : candies) {
            c += (i / mid);
        }
        return c >= k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1;
        long long r = *max_element(candies.begin(),candies.end());
        //if(r < k) return 0;

        int ans = 0;
        while(l<=r){
            long long mid = l + (r - l) / 2;
            if(solve(mid,candies,k)){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
    return ans;
    }
};