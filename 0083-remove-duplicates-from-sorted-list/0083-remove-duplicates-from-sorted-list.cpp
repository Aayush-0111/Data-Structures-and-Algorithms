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
            ListNode *temp = curr->next;
            curr->next = NULL;
            while(temp && curr->val == temp->val){
                ListNode *duplicate = temp;
                temp = temp->next;
                delete duplicate;
            }
            curr->next = temp;
            curr = temp;
        }
        return head;
    }
};