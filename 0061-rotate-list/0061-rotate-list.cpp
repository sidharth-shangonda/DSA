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
    ListNode* rotateLL(ListNode* head) {
        ListNode* prev=NULL;
        while(head) {
            ListNode* temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        ListNode* prev=head;
        int size=1;
        while(prev && prev->next) {
            prev=prev->next->next;
            size+=2;
        }
        if(!prev) {
            size-=1;
        }
        k=k%size;
        if(k==0) return head;
        head=rotateLL(head);
        prev=head;
        ListNode* temp=prev;
        while(k) {
            temp=prev;
            prev=prev->next;
            k--;
        }
        temp->next=rotateLL(prev);
        temp=temp->next;
        prev=temp;
        while(head!=temp) {
            ListNode* temp2=head->next;
            head->next=prev;
            prev=head;
            head=temp2;
        }
        return prev;
    }
};