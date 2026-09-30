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
    ListNode *merge(ListNode *l, ListNode *r){
        if(!l) return r;
        if(!r) return l;
        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;
        while(l && r){
            if(l->val < r->val){
                temp->next = l;
                temp = l;
                l = l->next;
            }else{
                temp->next = r;
                temp = r;
                r = r->next;
            }
        }
        temp->next = l ? l : r;
        return ans->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int n = lists.size();
        for(int gap{1}; gap < n; gap*=2){
            for(int i{0}; i+gap < n; i+=2*gap){
                lists[i] = merge(lists[i],lists[i+gap]);
            }
        }
        return lists[0];
    }
};