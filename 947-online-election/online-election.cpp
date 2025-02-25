class TopVotedCandidate {
public:
    vector<pair<int,int>> who;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n=persons.size();
        int currMax=persons[0];

        vector<int> freq(n,0);
        for(int i=0;i<persons.size();i++){
            freq[persons[i]]++;
            if(freq[persons[i]]>=freq[currMax]){
                currMax=persons[i];
            }
            who.push_back({times[i],currMax});
        }
    }
    
    int q(int t) {
        int index=0;
        int l=0,r=who.size()-1;

        while(l<=r){
            int mid=(l+r)/2;

            if(who[mid].first==t){
                index=mid;
                break;
            }
            if(who[mid].first<t){
                index=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return who[index].second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */