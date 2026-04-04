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
    int f(TreeNode* root, int &maxSum){
        if(root == NULL) return 0;

        // If a subtree returns a negative sum, 
        // we treat it as 0 (i.e., we don't include that path).
        int left = max(0, f(root->left, maxSum));
        int right = max(0, f(root->right, maxSum));

        // Update the global maximum: current node + its best left and right paths
        maxSum = max(maxSum, left + right + root->val);

        // Return the max path starting from this node going upwards to the parent
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        f(root,maxSum);
        return maxSum;
    }
};
