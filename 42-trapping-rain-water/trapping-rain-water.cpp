class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftMax(n, -1);
        vector<int> rightMax(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            if(!st.empty()){
                leftMax[i] = st.top();
                if(arr[i] > arr[st.top()]) st.push(i);
            }
            else st.push(i);
        }

        while(!st.empty()) st.pop();

        for (int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            if(!st.empty()){
                rightMax[i] = st.top();
                if(arr[i] > arr[st.top()]) st.push(i);
            }
            else st.push(i);
        }
        int ans = 0;

        for(int i=0;i<n;i++){
            if(leftMax[i] != -1 && rightMax[i] != -1){
                ans += min(arr[leftMax[i]],arr[rightMax[i]]) - arr[i];
            }
        }
    return ans;
    }
};