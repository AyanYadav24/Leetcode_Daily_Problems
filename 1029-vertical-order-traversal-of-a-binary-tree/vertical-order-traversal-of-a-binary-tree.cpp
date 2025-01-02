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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, vector<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});
        while (!q.empty()) {
            TreeNode* fnode = q.front().first;
            int hd = q.front().second.first;
            int lvl = q.front().second.second;
            q.pop();

            mp[hd][lvl].push_back(fnode->val);

            if (fnode->left)
                q.push({fnode->left, {hd - 1, lvl + 1}});
            if (fnode->right)
                q.push({fnode->right, {hd + 1, lvl + 1}});
        }
        for (auto i : mp) {
            vector<int> temp;
            for (auto j : i.second) {
                vector<int> values = j.second;
                sort(values.begin(), values.end());
                temp.insert(temp.end(), values.begin(), values.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};