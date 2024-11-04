class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0){
            return false;
        }
        
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }
        map<int,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            while(it->second>0){
                for(int i=0;i<groupSize;i++){
                    if(mp[it->first+i]>0){
                        mp[it->first+i]--;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};