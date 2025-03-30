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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* tmp = head;
        stack<int> st;
        for(int i=1 ; i<left ; i++) tmp = tmp->next;
        ListNode* tmp1 = tmp;
        for(int i = left ; i <= right ; i++){    
            st.push(tmp->val);
            if(tmp != nullptr)
                tmp = tmp->next;
        }

        for(int i = left ; i<=right ; i++)
        {
            tmp1 -> val = st.top();
            if(st.size() != 0)
                st.pop();
             if(tmp1 != nullptr)
                tmp1 = tmp1->next;
        }
        return head;
    }
};