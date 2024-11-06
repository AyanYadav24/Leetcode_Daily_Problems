class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int setBits[n];
        for(int i=0;i<n;i++){
            setBits[i] = __builtin_popcount(nums[i]);
        }
        for(int c : setBits){
            cout << c << " ";
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] > nums[j]){
                    if(setBits[i] != setBits[j]) return false; 
                }
            }
        }
    return true;
    }
};