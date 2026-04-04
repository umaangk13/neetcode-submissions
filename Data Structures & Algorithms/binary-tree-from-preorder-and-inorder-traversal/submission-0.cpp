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
        if(l > r) return NULL;

        int currVal = preorder[idx];
        TreeNode* root = new TreeNode(currVal);
        idx++;

        int currRootIdx = mp[currVal];

        int l1 = l, r1 = currRootIdx - 1;
        int l2 = currRootIdx + 1, r2 = r;
        root->left = f(l1,r1,idx,preorder,mp);
        root->right = f(l2,r2,idx,preorder,mp);

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
