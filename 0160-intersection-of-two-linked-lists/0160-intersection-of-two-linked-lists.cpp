/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;
        while(a->next) {
            a=a->next;
        }
        a->next=b;
        ListNode* slow=headA;
        ListNode* fast=headA;
        bool isCycle=false;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) {
                isCycle=true;
                break;
            }
        }
        if(!isCycle || fast!=slow) {
            a->next=NULL;
            return NULL;
        }
        slow=headA;
        while(fast!=slow) {
            slow=slow->next;
            fast=fast->next;
        }
        a->next=NULL;
        return slow;
    }
};