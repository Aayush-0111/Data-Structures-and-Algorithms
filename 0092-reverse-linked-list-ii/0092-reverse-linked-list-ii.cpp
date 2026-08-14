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
 vector<int> store;
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        int pos = 1;
        ListNode *temp = head, *lef = NULL, *rig = NULL;
        store.clear();
        store.reserve(right-left+1);
        store.reserve(right-left+1);
        while(temp && pos <= right){
            if(pos == left) lef = temp;
            if(pos == right) rig = temp;
            if(pos >= left && pos <= right){
                store.push_back(temp->val);
            }
            ++pos;
            temp = temp->next;
        }
        temp = lef;
        while(temp != rig->next){
            temp->val = store.back();
            store.pop_back();
            temp = temp->next;
        }
        return head;
    }
};