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
    void solve(ListNode *prev, ListNode* curr, ListNode* nxt, int pos, vector<int>& dist){
        if(!nxt) return;
        // check for minima and maxima
        if((curr->val < prev->val && curr->val < nxt->val) || (curr->val > prev->val && curr->val > nxt->val)) dist.push_back(pos);
        prev = curr;
        curr = nxt;
        nxt = nxt->next;
        ++pos;
        solve(prev,curr,nxt,pos,dist);
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1,-1};
        ListNode *prev = head, *curr = head->next, *nxt = head->next->next;
        int pos = 2;
        vector<int> dist;
        solve(prev,curr,nxt,pos,dist);
        if((int)dist.size() < 2) return {-1,-1};
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i{0}; i < dist.size()-1; ++i) mini = min(mini,dist[i+1] - dist[i]);
        maxi = dist.back() - dist[0];
        return {mini,maxi};
    }
};