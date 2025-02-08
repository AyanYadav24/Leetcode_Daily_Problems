class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int oneCount = 0;
        int rowNo = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    count++;
                }
            }
            if (count > oneCount) {
                oneCount = count;
                rowNo = i;
            }
        }
    return {rowNo,oneCount};
    }
};