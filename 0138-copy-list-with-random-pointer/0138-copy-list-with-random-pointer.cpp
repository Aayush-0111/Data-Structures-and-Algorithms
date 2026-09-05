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
        // Using only 1 map.
        if(!head) return NULL;
        Node *head2 = new Node(head->val);
        Node *curr = head->next; 
        Node *curr2 = head2;
        unordered_map<Node*,Node*> mp;
        mp[head] = head2;
        while(curr){
            Node *node = new Node(curr->val);
            curr2->next = node;
            mp[curr] = node;
            curr2 = node;
            curr = curr->next;
        }
        curr2 = head2;
        curr = head;
        // old node ke random ka current counterpart apne current ka random banega.
        while(curr){
            curr2->random = (mp.count(curr->random)) ? mp[curr->random] : NULL;
            curr = curr->next;
            curr2 = curr2->next;
        }
        return head2;
    }
};