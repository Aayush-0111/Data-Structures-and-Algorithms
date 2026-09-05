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
    bool isPalindrome(ListNode* head) {
        if(!head->next) return head;
        ListNode *slow = head, *fast = head->next;
        if(!fast->next) return slow->val == fast->val;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        ListNode *prev = NULL;
        while(fast){
            ListNode *next = fast->next;
            fast->next = prev;
            prev = fast;
            fast = next;
        }
        fast = prev;
        slow = head;
        while(fast && slow){
            if(slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true; 
    }
};