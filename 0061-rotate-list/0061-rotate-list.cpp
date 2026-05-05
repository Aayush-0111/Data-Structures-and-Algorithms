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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        // Instead of rotating manually, we just find the position of
        // the new head after rotating
        // Finding the lsize
        ListNode* curr = head;
        ListNode* last = head;
        int n = 0;
        while(curr != nullptr){
            n++;
            last = curr;
            curr = curr->next;
        }
        // Resizing k 
        k = k%n;
        if(k == 0) return head;
        // New head will be n-k-1 from the head
        ListNode* tail = head;
        for(int i = 0; i < n-k-1; i++) tail = tail->next;
        // connecting new head
        ListNode *newHead = tail->next;
        // creating the new tail
        tail->next = nullptr;
        // connecting the both
        last->next = head;
        return newHead;
    }
};