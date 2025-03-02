class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> v;
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;
        while(i<m && j<n){
            if(nums1[i][0] == nums2[j][0]){
                v.push_back({nums1[i][0],nums1[i][1] + nums2[j][1]});
                i++;j++;
            }
            else if(nums1[i][0] < nums2[j][0]){
                v.push_back({nums1[i][0],nums1[i][1]});
                i++;
            }
            else{
                v.push_back({nums2[j][0],nums2[j][1]});
                j++;
            }
        }
        while(i<m){
            v.push_back({nums1[i][0],nums1[i][1]});
            i++;
        }
        while(j<n){
            v.push_back({nums2[j][0],nums2[j][1]});
            j++;
        }
    return v;
    }
};