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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head;
        while(curr){
            if(curr->next && curr->val == curr->next->val){
                ListNode *temp = curr->next;
                while(temp && temp->val == curr->val){
                    temp = temp->next;
                }
                curr->next = temp;
                curr = temp;
            }else curr = curr->next;
        }
        return head;
    }
};