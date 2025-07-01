class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int Xor = 0 , xor1 = 0 , xor2 = 0;
        for(int num : nums){
            Xor ^= num;
        }
        int rsb = 0;
        while(((Xor >> rsb) & 1) != 1) rsb++;

        for(int num : nums){
            if((num >> rsb) & 1) xor1 ^= num;
            else xor2 ^= num;
        }
        return {xor1,xor2};
    }
};