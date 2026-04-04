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
    TreeNode* f(int l, int r, int &idx, vector<int>& preorder, unordered_map<int,int> &mp){
        // Base case: if bounds are invalid, return NULL. 
        // Notice we haven't touched idx yet.
        if(l > r) return NULL;

        // Now that we know it's a valid node, grab the value and THEN increment idx
        int currentVal = preorder[idx];
        TreeNode* root = new TreeNode(currentVal);
        idx++; 

        int currRootIdx = mp[currentVal];
        
        // Pass idx exactly as is. The pass-by-reference handles the global state.
        root->left = f(l, currRootIdx - 1, idx, preorder, mp);
        root->right = f(currRootIdx + 1, r, idx, preorder, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        int idx=0;
        return f(0,preorder.size()-1,idx,preorder,mp);
    }
};
