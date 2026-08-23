class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int lsum{0}, rsum{0}, ql{0}, qr{0};
        for(int l{0},r{n-1}; l<r; ++l,--r){
            lsum += (num[l] != '?') ? num[l]-'0' : 0;
            rsum += (num[r] != '?') ? num[r]-'0' : 0;
            ql += (num[l] == '?') ? 1 : 0;
            qr += (num[r] == '?') ? 1 : 0;
        }
        if(ql + qr == 0) return (lsum == rsum) ? false : true;
        else if((ql+qr)%2) return true;
        else if(ql == qr) return lsum != rsum;
        return (lsum-rsum) != 9*((qr-ql)/2);
    }
};