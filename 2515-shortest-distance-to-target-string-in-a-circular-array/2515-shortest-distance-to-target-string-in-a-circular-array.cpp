class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if(words[startIndex] == target) return 0;
        int n = words.size(), mini = INT_MAX;
        for(int i = 0; i < n; i++){
            if(words[i] == target) {
                int dist1 = abs(i-startIndex);
                int dist2 = n-dist1;
                mini = min(mini,min(dist1,dist2));
            }
        }
        return (mini == INT_MAX) ? -1 : mini;
    }
};