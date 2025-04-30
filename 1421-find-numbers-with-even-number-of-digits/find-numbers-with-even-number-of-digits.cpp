class Solution {
public:
    int digits(int num){
        int len = 0;
        while(num){
            len++;
            num/=10;
        }
    return len; 
    }
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(int& num : nums){
            if(digits(num) % 2 == 0) cnt++;
        }
    return cnt;
    }
};