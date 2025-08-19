class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev;
        unordered_set<int> curr;
        unordered_set<int> res;

        for(int num : arr){
            for(int x : prev) {
                curr.insert(x | num);
                res.insert(x | num);
            }
            curr.insert(num);
            res.insert(num);
            prev = curr;
            curr.clear();
        }
       return res.size();
    }
};