class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int curr = 0, maxi = 0, mini = 0;
        for(int& d : differences){
            curr += d;
            maxi = max(curr,maxi);
            mini = min(curr,mini);

            if((maxi - mini) > (upper - lower)) return 0;
        }
        return (upper - lower) - (maxi - mini) + 1;
    }
};