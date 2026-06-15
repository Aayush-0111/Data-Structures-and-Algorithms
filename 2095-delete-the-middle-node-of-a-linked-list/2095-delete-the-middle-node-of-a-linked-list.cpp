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
    int sizeofL(ListNode* head){
        int n = 0;
        ListNode* curr = head;
        while(curr){
            curr = curr->next;
            n++;
        }
        return n;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        int n = sizeofL(head);
        if(n == 1) return nullptr;
        ListNode* curr = head;
        ListNode* nxt = curr->next;
        ListNode* prv = nullptr;
        int s = floor(n/2);
        while(s--){
            prv = curr;
            curr = nxt;
            nxt = curr->next;
        }
        prv->next = nxt;
        return head;
    }
};