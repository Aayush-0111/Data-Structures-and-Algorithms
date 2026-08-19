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
    ListNode* swapNodes(ListNode* head, int k) {
        // idea is to first find the kth node from begining and store it's reference
        // then have another pointer(pointing at head) start traversing the list
        // along with the inital pointer pointing at kth node. 
        // Both pointers have a differnce of k positions b/w them
        // and by the time initial pointer reach the end, your second pointer will point to kth node.
        ListNode *firstK = NULL, *right = head, *left = head;
        while(right && --k) right = right->next;
        firstK = right;
        while(right->next){
            left = left->next;
            right = right->next;
        }
        swap(firstK->val,left->val);
        return head;
    }
};