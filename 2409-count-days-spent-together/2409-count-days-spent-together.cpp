static int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int am{arriveAlice[1]-'0' + (arriveAlice[0]-'0')*10}, bm{arriveBob[1]-'0' + (arriveBob[0]-'0')*10};
        int ad{arriveAlice[4]-'0' + (arriveAlice[3]-'0')*10}, bd{arriveBob[4]-'0' + (arriveBob[3]-'0')*10};
        int lam{leaveAlice[1]-'0' + (leaveAlice[0]-'0')*10}, lbm{leaveBob[1]-'0' + (leaveBob[0]-'0')*10};
        int lad{leaveAlice[4]-'0' + (leaveAlice[3]-'0')*10}, lbd{leaveBob[4]-'0' + (leaveBob[3]-'0')*10};
        int ans{0};
        if(am == bm){
            if(am == min(lam,lbm)){
                if(lam == lbm) return max(0, min(lad,lbd) - max(ad,bd) + 1);
                int endDay = (lam < lbm) ? lad : lbd;
                return max(0, endDay - max(ad,bd) + 1);
            }
            int start = max(ad,bd);
            ans += months[am-1] - start + 1;
            for(int i{am+1}; i <= min(lam,lbm); ++i){
                if(i == min(lam,lbm)){
                    ans += min(lad,lbd);
                    break;
                }
                ans += months[i-1];
            }
        }
        else{
            if(am > lbm || bm > lam || (am == lbm && ad > lbd) || (bm == lam && bd > lad)) return 0;
            if(am == lbm){
                if(lam == am) return min(lbd,lad) - ad + 1;
                return max(0, lbd - ad + 1);
            } 
            else if(bm == lam){
                if(lbm == bm) return min(lbd,lad) - bd + 1;
                return max(0, lad - bd + 1);
            } 
            int stm = max(am,bm);
            ans += (am > bm) ? months[stm-1] - ad + 1 : months[stm-1] - bd + 1;
            for(int i{stm+1}; i <= min(lam,lbm); ++i){
                if(i == min(lam, lbm)){
                    if(lam == lbm){
                        ans += min(lad,lbd);
                    }else{
                        ans += (lam < lbm) ? lad : lbd;
                    }
                    break;
                }
                ans += months[i-1];
            }
        }
        return ans;
    }
};