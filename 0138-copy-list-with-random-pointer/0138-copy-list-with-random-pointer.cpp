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
        if(!head) return NULL;
        Node *head2 = new Node(head->val);
        Node *curr = head->next; 
        Node *curr2 = head2;
        int idx1{1}, idx2{1};
        unordered_map<Node*,int> mp1;
        unordered_map<int,Node*> mp2;
        mp1[head] = idx1++;
        mp2[idx2++] = head2;
        while(curr){
            Node *node = new Node(curr->val);
            curr2->next = node;
            mp1[curr] = idx1++;
            mp2[idx2++] = node;
            curr2 = node;
            curr = curr->next;
        }
        curr2 = head2;
        curr = head;
        while(curr){
            int pos{mp1[curr->random]};
            curr2->random = mp2[pos];
            curr = curr->next;
            curr2 = curr2->next;
        }
        return head2;
    }
};