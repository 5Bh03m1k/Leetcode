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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* h1=nullptr;
        ListNode* h2=head;
        vector<int> ans;
        int cnt = 0;
        while(h2 != nullptr && h2 -> next != nullptr){
            if(h1 != nullptr && h2 -> next != nullptr){
               if ((h2->val > h1->val && h2->val > h2->next->val) || 
                    (h2->val < h1->val && h2->val < h2->next->val)) {
                    ans.push_back(cnt);
                }
            }
            h1 = h2;
            h2 = h2 -> next;
            cnt++;
        }

        if(ans.size() < 2){
            return {-1, -1};
        }

        int n = ans.size();
        
        int mini = INT_MAX;
        int maxi = ans[n-1] - ans[0];
        
        for (int i = 1; i < ans.size(); i++) {
            mini = min(mini, ans[i] - ans[i - 1]);
        }
        
        return {mini, maxi};
    }
};