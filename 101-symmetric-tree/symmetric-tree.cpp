/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            vector<int> temp;
            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                    temp.push_back(node->left->val);
                } else
                    temp.push_back(101);

                if (node->right) {
                    q.push(node->right);
                    temp.push_back(node->right->val);
                } else
                    temp.push_back(101);
            }
            int i = 0, j = temp.size() - 1;
            while (i < j) {
                if (temp[i] != temp[j])
                    return false;
                i++;
                j--;
            }
        }
        return true;
    }
};