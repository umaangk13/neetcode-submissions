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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p1, TreeNode* p2) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if(node->val > p1->val && node->val > p2->val){
                q.push(node->left);
            }
            else if(node->val < p1->val && node->val < p2->val){
                q.push(node->right);
            }
            else if(node->val == p1->val || node->val == p2->val){
                return node->val == p1->val?p1:p2;
            }
            else{
                return node;
            }
        }
        return NULL;
    }
};
