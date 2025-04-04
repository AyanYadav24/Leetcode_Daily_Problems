class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* a, TreeNode* b) {
        if (!root || root == a || root == b) return root;
        TreeNode* left = lca(root->left, a, b);
        TreeNode* right = lca(root->right, a, b);
        if (!left) return right;
        else if (!right) return left;
        else return root;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> arr;

        while (!q.empty()) {
            int size = q.size();
            arr.clear();

            for (int i = 0; i < size; i++) {
                TreeNode* t = q.front();
                q.pop();
                arr.push_back(t);

                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }

        if (arr.empty()) return nullptr;

        TreeNode* a = arr[0];
        TreeNode* b = arr[arr.size() - 1];

        return lca(root, a, b);
    }
};
