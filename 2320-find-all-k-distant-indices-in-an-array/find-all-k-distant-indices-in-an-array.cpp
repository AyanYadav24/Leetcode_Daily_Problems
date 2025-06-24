class Solution {
public:
    bool check(vector<int>& nums, int key, int i, int k){
        for(int j : nums){
            if(abs(j-i) <= k) return true;
        }
        return false;
    }
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans,st,indices;
        for(int i=0; i<nums.size() ;i++){
            if(nums[i] == key) st.push_back(i);
        }
        for(int i=0; i<nums.size(); i++){
            if(check(st,key,i,k)) indices.push_back(i);
        }
    return indices;
    }
};