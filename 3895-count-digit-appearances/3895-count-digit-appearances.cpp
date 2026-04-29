class Solution {
private:
    int digiCntr(int num, int digit){
        int cnt = 0;
        while(num){
            int x = num%10;
            if(x == digit) cnt++;
            num /= 10;
        }
        return cnt;
    }
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        for(int i : nums){
            count += digiCntr(i,digit);
        }
        return count;
    }
};