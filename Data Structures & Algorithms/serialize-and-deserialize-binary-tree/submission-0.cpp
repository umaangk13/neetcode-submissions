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

class Codec {
public:
    string getNext(string &data, int &i) {
        if (i >= data.size()) return "";
        int start = i;
        while (i < data.size() && data[i] != ',') {
            i++;
        }
        string res = data.substr(start, i - start);
        i++; // Move past the comma
        return res;
    }
    // Encodes a tree to a single string.
    // Serializes using BFS (Level Order)
    string serialize(TreeNode* root) {
        if (!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            if (!curr) {
                s += "n,"; // Using 'n' for null to keep string shorter
            } else {
                s += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Deserializes using manual pointer and a queue
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        int i = 0;
        // 1. Get the root value
        string val = getNext(data, i);
        TreeNode* root = new TreeNode(stoi(val));
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* parent = q.front(); q.pop();

            // 2. Process Left Child
            string leftVal = getNext(data, i);
            if (leftVal != "n") {
                parent->left = new TreeNode(stoi(leftVal));
                q.push(parent->left);
            }

            // 3. Process Right Child
            string rightVal = getNext(data, i);
            if (rightVal != "n") {
                parent->right = new TreeNode(stoi(rightVal));
                q.push(parent->right);
            }
        }
        return root;
    }
};
