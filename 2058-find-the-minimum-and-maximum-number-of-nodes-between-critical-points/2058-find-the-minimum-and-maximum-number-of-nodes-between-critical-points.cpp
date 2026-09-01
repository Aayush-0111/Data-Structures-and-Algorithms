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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1,-1};
        int mini{INT_MAX}, maxi{0}, currIdx{2}, prevIdx{0}, firstIdx{0};
        ListNode *prev = head, *curr = head->next, *next = head->next->next;
        while(next){
            if((curr->val > prev->val && curr->val > next->val) || (curr->val < prev->val && curr->val < next->val)){
                firstIdx = (!firstIdx) ? currIdx : firstIdx;
                prevIdx = (!prevIdx) ? currIdx : prevIdx;
                mini = (currIdx != prevIdx) ? min(mini,currIdx-prevIdx) : mini;
                prevIdx = currIdx;
            }
            prev = curr;
            curr = next;
            next = next->next;
            ++currIdx;
        }
        if(mini == INT_MAX) return {-1,-1};
        maxi = prevIdx - firstIdx;
        return {mini,maxi};
    }
};