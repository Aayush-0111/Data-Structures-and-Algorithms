class ProductOfNumbers {
    vector<int> nums;
    int lastZero{-1};
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(nums.empty() || !num){
            nums.push_back(num);
            lastZero = !num ? nums.size()-1 : -1;
            return;
        }
        if(nums.back() == 0){
            nums.push_back(num);
            return;
        }
        nums.push_back(num*nums.back());
    }
    
    int getProduct(int k) {
        int n = nums.size();
        if(k == n) return lastZero != -1 ? 0 : nums.back();
        int x{n-k-1};
        if(lastZero > x) return 0;
        return nums[x] != 0 ? nums[n-1]/nums[x] : nums[n-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */