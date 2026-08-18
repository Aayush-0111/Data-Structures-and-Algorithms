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
    int listLength(ListNode* head){
        int len{0};
        while(head){
            ++len;
            head = head->next;
        }
        return len;
    }
    ListNode* solve(ListNode* head, int k, int turn){
        if(!head || !turn) return head;
        ListNode *curr = head, *prev = NULL, *next = NULL;
        int temp{k};
        while(curr && temp--){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = solve(next,k,--turn);
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n{listLength(head)};
        int turn{(n - n%k)/k};
        return solve(head,k,turn);
    }
};