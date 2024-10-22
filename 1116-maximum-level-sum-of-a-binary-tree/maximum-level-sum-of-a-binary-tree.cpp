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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int maxi = INT_MIN;
        int lvl = 0,cnt =0,sum=0;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            cnt++;//level increased
            while(size > 0){
            TreeNode * node = q.front();
            sum += q.front() -> val;
            q.pop();

            if(node -> left) q.push(node -> left);
            if(node -> right) q.push(node -> right);
            size--;
            }
            cout <<"Level: " << cnt << " Sum: "<< sum << endl;
            if(sum > maxi){
                 lvl = cnt;
                 maxi = sum;
            }
            sum = 0;
        }
    return lvl;
    }
};