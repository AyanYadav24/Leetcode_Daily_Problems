class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0,c1=-1e9,c2=-1e9;

        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=c2){
                c1=nums[i];
                cnt1++;
            }
            else if(cnt2==0 && nums[i]!=c1){
                c2=nums[i];
                cnt2++;
            }
            else if(nums[i] == c1){cnt1++;}
            else if(nums[i] == c2){cnt2++;}
            else {
                cnt1--;
                cnt2--;
            } 
        }
        int ch1=0,ch2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==c1)ch1++;
            if(nums[i]==c2)ch2++;
        }
        vector<int> ans;
        if(ch1>(nums.size()/3)) ans.push_back(c1);
        if(ch2>(nums.size()/3)) ans.push_back(c2);
        return ans;
    }
};