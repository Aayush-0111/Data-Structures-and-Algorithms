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
    bool longer(ListNode *l1, ListNode *l2){
        ListNode *curr1 = l1, *curr2 = l2;
        while(curr1 && curr2){
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        if(!curr1 && !curr2) return true;
        return !curr1;
    }
    void reverse(ListNode* &head){
        ListNode *prev = NULL, *curr = head;
        while(curr){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void add(ListNode *l1, ListNode *l2){
        // here we are assuming l1 is the longer
        // we will be storing answer in l1.
        int carry{0};
        ListNode *curr1 = l1, *curr2 = l2;
        ListNode *prev1 = NULL;
        while(curr1 || curr2 || carry){
            int sum = carry;
            if(!curr1){
                ListNode *node = new ListNode(carry);
                prev1->next = node;
                carry = 0;
                break;
            }
            else if(!curr2 && carry){
                sum += curr1->val;
                curr1->val = sum%10;
                carry = sum/10;
                prev1 = curr1;
                curr1 = curr1->next;
                continue;
            }else if(curr2){
                sum += curr2->val;
                sum += curr1->val;
                curr1->val = sum%10;
                carry = sum/10;
                curr2 = curr2->next;
            }
            prev1 = curr1;
            curr1 = curr1->next;
        }
    } 
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // if longer returns true, meaning l1 is smaller
        // else l2 is smaller
        // we will use the other list to store the answer.
        int carry{0};
        if(longer(l1,l2)){
            add(l2,l1);
            return l2;
        }
        add(l1,l2);
        return l1;
    }
};