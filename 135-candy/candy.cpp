class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n,1);
        int min_candies = 0;

        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }
        for(int i=n-2;i>=0;i--){
             if(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]){
                candies[i] = candies[i+1] + 1;
            }
        }

        // if(ratings[0] > ratings[1] && candies[0] <= candies[1]) candies[0] = candies[1]++;
        // if(ratings[n-1] > ratings[n-2] && candies[n-1] <= candies[n-2]) candies[n-1] == candies[n-2]++;
        
        for(int i=0;i<n;i++){
            cout << candies[i] << " ";
            min_candies += candies[i];
        }
       return min_candies;
    }
};