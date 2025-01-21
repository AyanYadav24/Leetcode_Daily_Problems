class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);

        int l = 0;
        int h = m;

        while(l <= h){
            int p1 = l + (h - l) / 2;
            int p2 = (m+n+1)/2 - p1;

            int x1 = (p1==0) ? INT_MIN : nums1[p1-1];
            int x2 = (p2==0) ? INT_MIN : nums2[p2-1];
            int y1 = (p1==m) ? INT_MAX : nums1[p1];
            int y2 = (p2==n) ? INT_MAX : nums2[p2];

            if(x1 <= y2 and x2 <= y1){
                if((n+m)% 2 == 0){
                    return (max(x1,x2) + min(y1,y2)) / 2.00;
                }
                else{
                    return max(x1,x2);
                }
            }
            if(x1 > y2)
                h = p1 - 1;
            else 
                l = p1 + 1;
        }
        return -1;
    }
};