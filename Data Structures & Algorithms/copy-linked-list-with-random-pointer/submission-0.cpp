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
        unordered_map<Node*,Node*> mp;

        Node* curr = head;
        while(curr){
            Node* newNode = new Node(curr->val);
            mp[curr] = newNode;
            curr = curr->next;
        }

        curr = head;
        Node* newHead = mp[head];
        while(curr){
            Node* newCurr = mp[curr];
            Node* newNext = mp[curr->next];
            Node* newRand = mp[curr->random];
            newCurr->next = newNext;
            newCurr->random = newRand;
            // delete newCurr;
            // delete newNext;
            // delete newRand;
            curr = curr->next;
        }

        return newHead;
    }
};










