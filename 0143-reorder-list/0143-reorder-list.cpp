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
    ListNode* reverseLL(ListNode* head) {
        ListNode* temp=head;
        if(!temp) return NULL;
        ListNode* prev=NULL;
        while(temp) {
            ListNode* temp2=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp2;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next ) return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = NULL;
        // Reverse second half
        second = reverseLL(second);
        // Merge

        ListNode* st = head;
        while(st && second) {
            ListNode *stNext=st->next;
            ListNode *secondNext=second->next;
            st->next=second;
            second->next=stNext;
            st=stNext;
            second=secondNext;
        }
    }
};