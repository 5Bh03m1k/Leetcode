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
    void reorderList(ListNode* head) {
        deque<ListNode*> dq;
        ListNode* tmp = head;

        while(tmp != nullptr){
            dq.push_back(tmp);
            tmp = tmp->next;
        }
        tmp=head;
        //ListNode* tmp1;
        dq.pop_front();
        while(dq.size() != 0){
            tmp -> next = dq.back();
            dq.pop_back();
            tmp = tmp->next;

            if(dq.size() != 0){
                tmp->next = dq.front();
                dq.pop_front();
                tmp = tmp->next;
            }
        }
        tmp->next = nullptr;
        return;
    }
};