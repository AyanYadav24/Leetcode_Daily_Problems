class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int k) {
        priority_queue<pair<double,int>> pq;

        for(int i=0;i<classes.size();i++){
            double oldR = (double)classes[i][0]/classes[i][1];
            double newR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = newR - oldR;
            pq.push({delta,i});
        }

        while(k--){
            double delta = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            
            classes[ind][0]++;
            classes[ind][1]++; 

            double oldR = (double)classes[ind][0]/classes[ind][1];
            double newR = (double)(classes[ind][0]+1)/(classes[ind][1]+1);
            delta = newR - oldR;
            pq.push({delta,ind});
        }

        double ans = 0.0;
        for(int i=0; i<classes.size() ;i++){
            ans +=  (double)classes[i][0]/classes[i][1];
        }

        return ans / classes.size();
    }
};