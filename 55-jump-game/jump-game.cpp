class Solution {
public:
    bool canJump(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> jmps;

        if(nums.size() == 1) return true;

        for(int i = 0; i < nums.size(); i++)
        {
            while(!jmps.empty() && jmps.top() < i) jmps.pop();

            if(jmps.empty() && i != 0) return false;

            jmps.push(nums[i] + i);
        }

        return true;
    }
};