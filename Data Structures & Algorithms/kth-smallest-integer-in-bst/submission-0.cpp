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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;

        while (curr) {
            // CASE 1: No left child. 
            // We can't go left, so "process" this node and move right.
            if (!curr->left) {
                k--; 
                if (k == 0) return curr->val; // Found the kth smallest!
                curr = curr->right;
            } 
            // CASE 2: There is a left child.
            else {
                // Find the Inorder Predecessor (Rightmost node in the left subtree)
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }

                // SUBCASE A: Predecessor's right is NULL.
                // We haven't visited this left subtree yet. 
                // Create a 'thread' back to curr so we can return later.
                if (!pred->right) {
                    pred->right = curr; 
                    curr = curr->left; // Now go explore the left subtree
                } 
                // SUBCASE B: Predecessor's right is already pointing to curr.
                // This means we just finished visiting the left subtree!
                else {
                    pred->right = nullptr; // Clean up: break the temporary thread
                    k--;                   // "Process" the current node
                    if (k == 0) return curr->val;
                    curr = curr->right;    // Left and Root are done, move to right subtree
                }
            }
        }
        return -1; // Should not be reached in a valid BST with k nodes
    }
};
