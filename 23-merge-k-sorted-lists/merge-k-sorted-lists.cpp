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
private:
    priority_queue<int , vector<int> , greater<int>> q;
public:
    ListNode* mergeKLists(vector<ListNode*>& l) {
        for(int i = 0 ; i < l.size() ; i++)
        {
            // l[i];
              while(true)
            {
                if(l[i] == nullptr) break;
                q.push(l[i]->val);
                l[i] = l[i]->next;
            }
        }
        if(q.size() == 0) return   nullptr;
        ListNode* head = new ListNode(q.top());
        ListNode* node = head;
        q.pop();
        while(q.size() > 0)
        {
            ListNode* h = new ListNode(q.top());
            node->next = h;
            q.pop();
            node = h;
        }
        return head;

    }
};