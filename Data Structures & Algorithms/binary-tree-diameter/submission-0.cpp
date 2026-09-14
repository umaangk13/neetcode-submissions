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
    int result=0;
    int f(TreeNode* root){
        if(root == nullptr) return 0;

        int leftHeight = f(root->left);
        int rightHeight = f(root->right);
        result = max(result, rightHeight+leftHeight);

        return 1 + max(leftHeight,rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        f(root);
        return result;
    }
};
