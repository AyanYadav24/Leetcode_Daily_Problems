class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i=0,j=0;
        while (i < v1.length() || j < v2.length()) {
            string d1 = "", d2 = "";
            while (i < v1.length() && v1[i] != '.') {
                d1 += v1[i];
                i++;
            }
            while (j < v2.length() && v2[j] != '.') {
                d2 += v2[j];
                j++;
            }
            cout << d1 << " " << d2 << endl;
            int f = d1.empty() ? 0 : stoi(d1);
            int l = d2.empty() ? 0 : stoi(d2);
            if (f > l)
                return 1;
            if (f < l)
                return -1;
            i++;j++;
        }
        return 0;
    }
};