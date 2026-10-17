class Solution {
private:
    int digSum(int n){
        int sum{0};
        while(n){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int swaps{0};
        vector<int> arr;
        arr.reserve(n);
        for(int i{0}; i < n; ++i){
            arr.push_back(digSum(nums[i]));
        }
        vector<int> idxs(n);
        iota(idxs.begin(),idxs.end(),0);
        sort(idxs.begin(), idxs.end(), [&](int a, int b){
            if(arr[a] != arr[b]) return arr[a] < arr[b];
            return nums[a] < nums[b];
        });
        vector<int> target(n);
        for(int i{0}; i < n; ++i) target[idxs[i]] = i;
        vector<bool> vis(n,false);
        for(int i{0}; i < n; ++i){
            if(vis[i] || target[i] == i) continue;
            int j{i}, len{0};
            while(!vis[j]){
                vis[j] = true;
                j = target[j];
                ++len;
            }
            swaps += len-1;
        }
        return swaps;         
    }
};