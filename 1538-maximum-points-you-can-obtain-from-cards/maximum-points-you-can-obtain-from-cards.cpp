class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size();
        int sum = 0,l = k-1,r = n-1;
        for(int i=0;i<k;i++){
            sum += cp[i];
        }
        int maxi = sum;
        while(l>=0){
            sum -= cp[l];
            l--;
            sum += cp[r];
            r--;
            maxi = max(sum,maxi);
        }
        return maxi;
    }
};