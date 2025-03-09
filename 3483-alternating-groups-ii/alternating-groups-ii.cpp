class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int i = 0, j = 1, ans = 0, prev = colors[0];
        while(j<n+k-1){
            if(colors[j%n] == prev){
                i=j;
            }
            if(j-i+1 == k){
                ans++;
                i++;
            }
            prev = colors[j%n];
            j++;
        }
    return ans;
    }
};