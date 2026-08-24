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
        ListNode *curr = head, *prev = NULL;
        while(curr){
            ListNode *temp = curr->next;
            if(temp && temp->val == curr->val){
                while(temp && temp->val == curr->val){
                    ListNode *duplicate = temp;
                    temp = temp->next;
                    delete duplicate;
                }
                ListNode *dup = curr;
                delete dup;
                if(!prev){
                    head = temp;
                    curr = temp;
                }else{
                    prev->next = temp;
                    curr = temp;
                }
                
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};