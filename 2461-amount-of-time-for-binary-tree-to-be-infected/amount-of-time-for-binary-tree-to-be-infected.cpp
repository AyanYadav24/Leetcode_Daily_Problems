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
    TreeNode* node = NULL;
    unordered_map<TreeNode*,TreeNode*> parent;
    void constructParent(TreeNode* root, int start){
        queue<TreeNode*> q; 
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                if(temp -> val == start) node = temp;
                q.pop();
                if(temp -> left){
                    parent[temp->left]=temp;
                    q.push(temp -> left);
                }
                if(temp -> right){
                    parent[temp->right]=temp;
                    q.push(temp -> right);
                }
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        constructParent(root,start);
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> vis;
        int minutes = 0;
        q.push(node);
        while(!q.empty()){
            //bool flag  = false;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                vis[temp] = true;
                if(temp -> left && !vis[temp -> left]){
                    q.push(temp -> left);
                    //flag = true;
                }
                if(temp -> right && !vis[temp -> right]){
                    q.push(temp -> right);
                    //flag = true;
                }
                if(temp != root && !vis[parent[temp]]){
                    q.push(parent[temp]);
                    //flag = true;
                }
            }
            minutes++;
        }
    return minutes-1;
    }
};