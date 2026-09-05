/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Without using extra space
        if(!head) return NULL;
        Node *head2 = new Node(head->val);
        Node *next = head->next;
        head->next = head2;
        head2->next = next;
        Node *curr = next;
        while(curr){
            next = curr->next;
            Node *node = new Node(curr->val);
            curr->next = node;
            node->next = next;
            curr = next;
        }
        curr = head;
        next = head2;
        while(next){
            if(curr->random) next->random = curr->random->next;
            if(!next->next) break;
            curr = curr->next->next;
            next = next->next->next;
        }
        curr = head;
        next = head2;
        while(curr && next){
            curr->next = next->next;
            curr = curr->next;
            next->next = (curr) ? curr->next : NULL;
            next = next->next;
        }
        return head2;
    }
};