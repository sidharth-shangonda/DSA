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
    void reverseLL(ListNode* head) {
        ListNode* temp=head->next;
        if(!temp ||!temp->next) return;
        ListNode* prev=NULL;
        while(temp) {
            ListNode* temp2=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp2;
        }
        head->next=prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next ) return;
        while(head) {
            reverseLL(head);
            head=head->next;
        }
    }
};