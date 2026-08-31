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
        if(!head || !head->next || !head->next->next) return {-1,-1};
        ListNode* prev=head;
        ListNode* cur=head->next;
        int i=1;
        int st=-1;
        int ed=-1;
        int minPeak=INT_MAX;
        while(cur && cur->next) {
            ListNode* next=cur->next;
            bool critical=((prev->val < cur->val) && (cur->val > next->val)) || ((prev->val > cur->val) && (cur->val < next->val));
            if(critical) {
                if(st==-1) {
                    st=i;
                } else {
                    minPeak=min(minPeak,i-ed);
                }
                ed=i;
            }
            prev=cur;
            cur=cur->next;
            i++;
        }
        if(st==ed) {
            return {-1,-1};
        }
        return {minPeak,ed-st};
    }
};