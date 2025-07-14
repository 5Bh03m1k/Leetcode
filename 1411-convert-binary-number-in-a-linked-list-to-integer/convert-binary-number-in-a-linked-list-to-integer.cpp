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
    int get(ListNode* node,int n)
    {
        if(node == nullptr) return n;

        n = n<<1;

        if(node->val)   n++;

        return get(node->next,n);
    }
public:
    int getDecimalValue(ListNode* head) {
        return get(head,0);
    }
};