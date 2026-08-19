class Solution {
private:
    static inline int helper(const vector<int>& seat){
        int n{(int)seat.size()};
        if(n == 0) return 0;
        bool slot1{true}, slot2{true}, slot3{true};
        for(int i{0}; i < n; ++i){
            slot1 = slot1 && !(seat[i] >= 2 && seat[i] <= 5);
            slot2 = slot2 && !(seat[i] >= 4 && seat[i] <= 7);
            slot3 = slot3 && !(seat[i] >= 6 && seat[i] <= 9);
        }
        if(slot1 && slot3) return 2; // slot2 have to be true anyways so not point checking.
        if(slot1 || slot2 || slot3) return 1;
        return 0; 
    }
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m{(int)reservedSeats.size()}, ans{0};
        int reservedRows{0};
        vector<int> seat;
        sort(reservedSeats.begin(),reservedSeats.end());
        for(int i{0}; i < m; ++i){
            int j{i}, row{reservedSeats[i][0]};
            while(j < m && reservedSeats[j][0] == row){
                seat.push_back(reservedSeats[j][1]);
                ++j;
            }            
            ans += helper(seat);
            seat.clear();
            ++reservedRows;
            i = j-1;
        }
        ans += (n-reservedRows)*2;
        return ans;
    }
};