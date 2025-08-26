class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
    int maxArea = 0;
    double maxDiag = 0;

    for (const auto& d : dim) {
        int len = d[0];
        int wid = d[1];
        double diag = sqrt(len * len + wid * wid);
        int area = len * wid;

        if (diag > maxDiag) {
            maxDiag = diag;
            maxArea = area;
        } else if (diag == maxDiag && area > maxArea) {
            maxArea = area;
        }
    }
    return maxArea;
    }
};