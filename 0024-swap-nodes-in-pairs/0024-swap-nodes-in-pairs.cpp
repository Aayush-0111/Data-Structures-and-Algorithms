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
private:
    ListNode* solve(ListNode* head){
        if(!head || !head->next) return head;
        ListNode *curr = head, *prev = NULL, *next = NULL;
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
        curr->next = prev;

        head->next = solve(next);
        return curr;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        return solve(head);
    }
};