class Solution {
private:
    int solve(vector<int>& s1, vector<int>& d1, vector<int>& s2, vector<int>& d2){
        int n = s1.size(), m = s2.size();
        int fin1 = INT_MAX, fin2 = INT_MAX;
        for(int i = 0; i < n; i++){
            fin1 = min(fin1,s1[i]+d1[i]);
        }
        for(int j = 0; j < m; j++){
            fin2 = min(fin2,max(fin1,s2[j])+d2[j]);
        }
        return fin2;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int duration1 = solve(landStartTime,landDuration,waterStartTime,waterDuration);
        int duration2 = solve(waterStartTime,waterDuration,landStartTime,landDuration);
        return min(duration1,duration2);
    }
};