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
    ListNode* partition(ListNode* head, int x) {
        ListNode* tmp = head;

        queue<int> sl;
        queue<int> gt;

        while(tmp != nullptr){
            if(tmp -> val < x)  sl.push(tmp->val);
            else    gt.push(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;
        while(sl.size() != 0){
            tmp->val = sl.front();
            sl.pop();
            tmp = tmp->next;
        }
        while(gt.size() != 0){
            tmp->val = gt.front();
            gt.pop();
            tmp = tmp->next;
        }
        return head;
    }
};