class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!used[j] && fruits[i] <= baskets[j] ){ fruits[i] = 0; used[j] = true; break;}
            }
        }
        int cnt = 0;
        for(int n : fruits) {
            cout << n << " ";
            if(n != 0) cnt++;
        }
    return cnt;
    }
};