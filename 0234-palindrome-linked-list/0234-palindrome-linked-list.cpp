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
        if(!head->next) return true;
        vector<int> temp;
        ListNode *curr = head;
        // put elements of LL in an array
        while(curr){
            temp.push_back(curr->val);
            curr = curr->next;
        }
        // reverse the linked list
        ListNode *prev = NULL;
        curr = head;
        while(curr){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        curr = head;
        // compare the elements of reverse list with the array elements
        int i{0};
        while(curr){
            if(curr->val != temp[i++]) return false;
            curr = curr->next;
        }
        return true;
    }
};