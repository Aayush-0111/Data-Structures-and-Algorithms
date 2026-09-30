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
    ListNode *midLL(ListNode *head){
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *merge(ListNode *l1, ListNode *l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;
        while(l1 && l2){
            if(l1->val < l2->val){
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }else{
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        while(l1){
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
        }
        while(l2){
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
        }
        return ans->next;
    }
    ListNode *sort(ListNode *head){
        if(!head || !head->next) return head;
        ListNode *left = head;
        ListNode *mid = midLL(head);
        ListNode *right = mid->next;
        mid->next = NULL;
        // sort left and right parts
        left = sort(left);
        right = sort(right);
        // merge left and right parts
        head = merge(left,right);
        return head;
    }   
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(lists.empty()) return NULL;
        ListNode *head = NULL;
        int i{0};
        while(i < n && !lists[i]) ++i;
        if(i >= n) return NULL;
        head = lists[i];
        ListNode *temp = head;
        while(temp->next) temp = temp->next;
        for(int j{i+1}; j < n; ++j){
            if(!lists[j]) continue;
            temp->next = lists[j];
            while(temp->next) temp = temp->next;
        }
        // now apply merge sort on the list
        head = sort(head);
        return head;
    }
};