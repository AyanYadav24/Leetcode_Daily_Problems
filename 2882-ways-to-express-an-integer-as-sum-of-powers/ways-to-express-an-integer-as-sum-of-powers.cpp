class Solution {
private:
    int mod = 1e9+7;
    int func(vector<int> &arr , int n , int i , int sum , vector<vector<int>> &dp ){
        if(sum == n ) return 1;
        if(i == arr.size() || sum > n){
            return 0;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        int take = func(arr , n , i+1 ,sum + arr[i] , dp ); 
        int notake = func(arr , n , i+1 ,sum , dp);
        
        return dp[i][sum] =  (take + notake) % mod;
    }

public:

    int numberOfWays(int n, int x) {
        vector<int> arr;
        for(int i = 1 ; n >= pow(i , x);i++){
            arr.push_back( (int)pow(i , x));
        }
        vector<vector<int>> dp(arr.size()+1 , vector<int>(n+1 , -1));

        return func(arr , n , 0 , 0 , dp );
    }
};