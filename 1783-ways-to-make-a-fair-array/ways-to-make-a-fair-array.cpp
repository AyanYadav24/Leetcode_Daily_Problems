class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        vector<int> oddSum(n,0);
        vector<int> evenSum(n,0);

        evenSum[0] = nums[0];
        for(int i=1;i<n;i++){
            if(i%2==0){
                evenSum[i] = evenSum[i-1] + nums[i];
                oddSum[i] = oddSum[i-1];
            }
            else{
                oddSum[i]  = oddSum[i-1] + nums[i];
                evenSum[i] = evenSum[i-1];
            }
        }
        // for(int i=0;i<n;i++){
        //     cout << "For index "<< i << " -> " << "even : " << evenSum[i] << " odd : " << oddSum[i] << endl;
        // }
        
        for(int i=1;i<n;i++){
            int total_evenSum = evenSum[i-1] + oddSum[n-1] - oddSum[i];
            int total_oddSum = oddSum[i-1] + evenSum[n-1]  -  evenSum[i];

            if(total_evenSum == total_oddSum) cnt++;//check for fair array condition
        }
        if(evenSum[n-1] - nums[0] == oddSum[n-1]) cnt++;
    return cnt;
    }
};