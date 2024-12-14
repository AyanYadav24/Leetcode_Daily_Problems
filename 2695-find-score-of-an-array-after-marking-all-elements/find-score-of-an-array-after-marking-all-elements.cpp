class Solution {
public:
    long long findScore(vector<int>& nums) {
        //vector to store <num,index> as pair
        vector<pair<int,int>> vec;

        for(int i=0; i<nums.size() ;i++){
            vec.push_back({nums[i],i});
        }

        //sorting elements to access smallest element first
        sort(vec.begin(),vec.end());

        //To store visited elements
        vector<bool> vis(nums.size());
        long long sum = 0;

        for(int i=0; i<vec.size() ;i++){
            int num = vec[i].first;
            int idx = vec[i].second;

            if(vis[idx] == false){
                //accumulating num to sum 
                sum += num;

                //marking neighbour elements as visited
                if(idx - 1 >= 0) vis[idx-1] = true;
                if(idx + 1 <= nums.size()) vis[idx+1] = true;


            }
        }
        return sum;
    }
};