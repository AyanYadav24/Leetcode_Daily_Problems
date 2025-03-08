class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ans=INT_MAX;
        int i=0,j=0,cnt=0;
        while(j<n){
            if(blocks[j]=='W') cnt++;
            if(j-i+1 == k){
                ans = min(ans,cnt);
                if(blocks[i]=='W') cnt--;
                i++;
            }
            j++;
        }
        return ans;
    }
};