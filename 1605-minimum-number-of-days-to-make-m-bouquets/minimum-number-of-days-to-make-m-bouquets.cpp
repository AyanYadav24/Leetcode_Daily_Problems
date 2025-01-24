class Solution {
public:
    bool possible(int days,int m, int k, vector<int>& bloomDay){
        int flowers = 0, bou = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= days){
                flowers++;
                if(flowers == k){
                    bou++;
                    if(bou==m) return true;
                    flowers=0;
                }
            }
            else flowers = 0;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 0, h = *max_element(bloomDay.begin(),bloomDay.end()), ans = -1;
        while(l<=h){
            int mid = l + (h - l) / 2;
            if(possible(mid,m,k,bloomDay)){
                ans = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};