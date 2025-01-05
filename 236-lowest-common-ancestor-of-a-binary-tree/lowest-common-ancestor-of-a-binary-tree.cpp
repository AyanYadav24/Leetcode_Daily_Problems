/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool path (TreeNode* root, TreeNode* p, vector<TreeNode*>& res){
        if(p == NULL || root == NULL) return false;

        res.push_back(root);

        if(root == p) return true;

        if(path(root->left,p,res) || path(root->right,p,res)) return true;

        res.pop_back();

        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> f;
        vector<TreeNode*> l;

        path(root,p,f);
        path(root,q,l);

        int i=0;
        while(i < f.size() && i < l.size() && f[i] == l[i]) i++;
        return f[i-1];
    }
};