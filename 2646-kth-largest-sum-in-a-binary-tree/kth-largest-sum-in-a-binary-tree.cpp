/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        vector<long long> sums;
        long long sum = 0;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            while(size > 0){
            TreeNode * node = q.front();
            sum += q.front() -> val;
            q.pop();

            if(node -> left) q.push(node -> left);
            if(node -> right) q.push(node -> right);
            size--;
            }
            sums.push_back(sum);
            sum = 0;
        }
        sort(begin(sums),end(sums));
    return sums.size() >= k ? sums[sums.size() - k] : -1;
    }
};