class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        // Step 1: Insert copied nodes
        Node* curr = head;

        while (curr) {
            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        // Step 2: Set random pointers
        curr = head;

        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;

            curr = curr->next->next;
        }

        // Step 3: Separate the two lists
        Node* copyHead = head->next;
        curr = head;

        while (curr) {
            Node* copy = curr->next;

            curr->next = copy->next;

            if (copy->next)
                copy->next = copy->next->next;

            curr = curr->next;
        }

        return copyHead;
    }
};