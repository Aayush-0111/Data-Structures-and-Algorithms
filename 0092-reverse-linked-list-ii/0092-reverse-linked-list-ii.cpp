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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 1 2->3->4 5
        // 1 2 - _ ->4 5
        // 1 2(->4) <-3 (->4) 5
        // 1 -> 2(->4)<-3 (->4) -> 5
        // 1 -> 3 -> 2 -> 4 -> 5
        // 13 2->4->5
        // 13 2 - _ -> 5
        // 13 2(->5) <- 4 (->5)
        // 1->4->3->2->5
        if(!head || left==right) return head;
        ListNode* dummy = new ListNode(0); // in case, left is 1.
        dummy->next = head;
        ListNode* prev = dummy;
        int i = 0; 
        while(i < left-1) {
            prev = prev->next;
            ++i;
        }
        // run loop till right-left times
        i = 0;
        ListNode* curr = prev->next;
        while(i < right-left){
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
            ++i;
        }
        return dummy->next;
    }
};