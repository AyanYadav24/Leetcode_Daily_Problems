class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> leftsmallest(n,-1);
        vector<int> rightsmallest(n,n);

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) leftsmallest[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) rightsmallest[i] = st.top();
            st.push(i);
        }

        int max_area = 0;
        for(int i=0;i<n;i++){
            int width = rightsmallest[i] - leftsmallest[i] - 1;
            max_area = max(max_area,arr[i] * width);
        }
        return max_area;
    }
};