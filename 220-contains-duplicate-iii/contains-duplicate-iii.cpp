class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& arr, int indexDiff , int valueDiff) {
           set<int> mp;
           int j=0;
           for(int i=0;i<arr.size();i++){
            if(i>indexDiff){
              mp.erase(arr[j]);
              j++;
            }
            auto it=mp.lower_bound(arr[i]-valueDiff);   
            if(it!=mp.end()){
                  long int minVal=*it;
                  long int maxVal=valueDiff+arr[i];

                  if(minVal<=maxVal)return true;
            }
            mp.insert(arr[i]);
           }
    
           return false;
}
};