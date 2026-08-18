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
    ListNode* reverse(ListNode* &head){
        ListNode *prev = NULL, *next = NULL;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *temp1 = head;
        int x{k};
        while(temp1 && --x) temp1 = temp1->next;        
        head = reverse(head);
        ListNode *temp2 = head;
        while(temp2 && --k) temp2 = temp2->next;
        int val1{temp1->val}, val2{temp2->val};
        temp1->val = val2;
        temp2->val = val1;
        head = reverse(head);
        return head;
    }
};