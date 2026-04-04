/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> hp;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        for(int i=0;i<lists.size();i++){
            if (lists[i]) hp.push({lists[i]->val,lists[i]});
        }

        while(!hp.empty()){
            auto it = hp.top();
            hp.pop();
            curr->next = it.second;
            curr = curr->next;
            if (curr->next) hp.push({curr->next->val,curr->next});
        }

        return dummy->next;
    }
};