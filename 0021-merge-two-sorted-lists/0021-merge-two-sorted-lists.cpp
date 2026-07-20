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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=NULL;
        ListNode* ptr=head;
        while(list1 && list2) {
            ListNode* newNode= new ListNode();
            if(list1->val>list2->val) {
                newNode->val=list2->val;
                if(ptr==NULL) { 
                    ptr=newNode;
                    head=ptr;
                    list2=list2->next;
                    continue;
                }
                ptr->next=newNode;
                ptr=newNode;
                list2=list2->next;
            } else {
                newNode->val=list1->val;
                if(ptr==NULL) { 
                    ptr=newNode;
                    head=ptr;
                    list1=list1->next;
                    continue;
                }
                ptr->next=newNode;
                ptr=newNode;
                list1=list1->next;
            }
        }
        while(list1) {
            ListNode* newNode= new ListNode(list1->val);
            if(ptr==NULL) { 
                ptr=newNode;
                head=ptr;
                list1=list1->next;
                continue;
            }
            ptr->next=newNode;
            ptr=newNode;
            list1=list1->next;
        }
        while(list2) {
            ListNode* newNode= new ListNode(list2->val);
            if(ptr==NULL) { 
                ptr=newNode;
                head=ptr;
                list2=list2->next;
                continue;
            }
            ptr->next=newNode;
            ptr=newNode;
            list2=list2->next;
        }
        return head;
    }
};