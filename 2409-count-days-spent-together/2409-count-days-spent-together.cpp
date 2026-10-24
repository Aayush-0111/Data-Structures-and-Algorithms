class Solution {
private:
    static inline int dayOfYear(const string& day, const vector<int>& prefix){
        int month{stoi(day.substr(0,2))}, date{stoi(day.substr(3))};
        return prefix[month-1] + date;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        static int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> prefix(1,0);
        for(int& i : months) prefix.emplace_back(prefix.back() + i);
        int aliceArrival{dayOfYear(arriveAlice, prefix)};
        int bobArrival{dayOfYear(arriveBob, prefix)};
        int aliceDep{dayOfYear(leaveAlice, prefix)};
        int bobDep{dayOfYear(leaveBob, prefix)};
        return max(0, min(aliceDep, bobDep) - max(aliceArrival, bobArrival) + 1);
    }
};