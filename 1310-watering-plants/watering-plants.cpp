class Solution {
public:
    int wateringPlants(vector<int>& arr, int c) {
        int n = arr.size();
        int i=0,s=0,w=c;
        while(i<n){
            if(w>=arr[i]){
                w-=arr[i];
                s++;
            }
            else{
                s+=(2*i+1);
                w=c;
                w-=arr[i];
            }
            i++;
        }
        return s;
    }
};