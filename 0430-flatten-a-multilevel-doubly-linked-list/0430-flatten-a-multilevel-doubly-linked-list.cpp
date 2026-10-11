/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* ptr=head;
        while(ptr) {
            if(ptr->child) {
                Node* tail=ptr->child;

                while(tail->next) tail=tail->next;

                tail->next=ptr->next;
                if(ptr->next) ptr->next->prev=tail;

                ptr->next=ptr->child;
                ptr->child->prev=ptr;
                ptr->child=NULL;
            }
            ptr=ptr->next;
        }
        return head;
    }
};