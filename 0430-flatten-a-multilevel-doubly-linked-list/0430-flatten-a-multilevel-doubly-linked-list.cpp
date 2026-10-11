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
        stack<Node*> s;
        Node* ptr=head;
        while(ptr) {
            if(ptr->child) {
                if(ptr->next) s.push(ptr->next);
                ptr->next=ptr->child;
                ptr->child->prev=ptr;
                ptr->child=NULL;
            }else if(!ptr->next && !s.empty()) {
                Node* temp=s.top();
                s.pop();
                ptr->next=temp;
                temp->prev=ptr;
            }
            ptr=ptr->next;
        }
        return head;
    }
};