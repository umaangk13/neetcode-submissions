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
    bool isSameTree(TreeNode* p1, TreeNode* p2) {
        queue<TreeNode*> q;
        q.push(p1);
        q.push(p2);
        while(!q.empty()){
            TreeNode* n1 = q.front(); q.pop();
            TreeNode* n2 = q.front(); q.pop();

            // Both are null - this pair matches, keep checking others
            if (!n1 && !n2) continue;
            
            // One is null or values don't match - trees are different
            if (!n1 || !n2 || n1->val != n2->val) return false;

            // Push children in pairs (Left with Left, Right with Right)
            q.push(n1->left);
            q.push(n2->left);
            q.push(n1->right);
            q.push(n2->right);
        }
        return true;
    }
};
