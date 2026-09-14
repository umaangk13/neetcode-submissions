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
    bool flag = true;
    int f(TreeNode* root){
        if(root == nullptr) return 0;

        int leftHeight = f(root->left);
        int rightHeight = f(root->right);
        if(abs(leftHeight - rightHeight) > 1) flag = false;

        return 1 + max(leftHeight,rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        f(root);
        return flag;
    }
};
