/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Interleave
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Step 2: Assign Random Pointers
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the lists
        Node* dummy = new Node(0);
        Node* copyTail = dummy;
        curr = head;

        while (curr) {
            // Extract the copy
            copyTail->next = curr->next;
            copyTail = copyTail->next;

            // Restore the original
            curr->next = curr->next->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};