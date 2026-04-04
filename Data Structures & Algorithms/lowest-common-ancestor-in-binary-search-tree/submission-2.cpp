/**
 * Definition for a binary tree curr.
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
        TreeNode* curr = root;
        while(curr){
            if(curr->val > p1->val && curr->val > p2->val){
                curr = curr->left;
            }
            else if(curr->val < p1->val && curr->val < p2->val){
                curr = curr->right;
            }
            else{
                // We found the split point or one of the nodes itself
                return curr;
            }
        }
        return NULL;
    }
};
