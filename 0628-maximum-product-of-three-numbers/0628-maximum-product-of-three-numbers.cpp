class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int m1 = INT_MIN, m2 = INT_MIN, m3 = INT_MIN;
        for(int& i : nums){
            if(i > m1){
                m3 = m2;
                m2 = m1;
                m1 = i;
            }else if(i > m2){
                    m3 = m2;
                    m2 = i;
            }else if(i > m3) m3 = i;
        }
        int l1 = INT_MAX, l2 = INT_MAX, l3 = INT_MAX;
        for (int &i : nums) {
            if (i < l1) {
                l3 = l2;
                l2 = l1;
                l1 = i;
            } else if (i < l2) {
                l3 = l2;
                l2 = i;
            } else if (i < l3) {
                l3 = i;
            }
        }
        return max(m1*m2*m3,l1*l2*m1);
    }
};