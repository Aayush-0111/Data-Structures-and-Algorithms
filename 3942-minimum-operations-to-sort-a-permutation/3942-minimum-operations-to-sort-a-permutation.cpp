class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end())) return 0;
        // Nums is a permuation
        // We want to check if it maintains the cyclic sorted order
        // that order can be increasing or decreasing, but it will be sorted
        // if not we return -1.
        // Now the key is to know the pos of '0'
        // if array is increasing sorted, any element of the permuation/nums
        // can be reached by adding that number in the pos of '0'.
        // EX: IF THE ARRAY IS VALID, WE SHOULD BE ABLE TO FIND '2' TWO STEPS AHEAD OF '0'.
        
        int n = nums.size();
        if(n == 2) return 1;
        int k = find(nums.begin(),nums.end(),0)-nums.begin();
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(nums[(k+i)%n] != i){
                flag = false;
                break;
            }
        }
        if(flag) {
            // now either we can shift the 0 to the starting pos
            int ops1 = k;
            // or we can reverse the array, than shift the 0 to the end(continuous left shifting) 
            // than we can reverse the array and 0 will be at start. this will take 2 rev ops.
            // [2,3,4,0,1] -> [1,0,4,3,2] -> [0,4,3,2,1] -> [4,3,2,1,0] -> [0,1,2,3,4]
            int ops2 = n-k+2;
            // take the smallest of the two
            return min(ops1,ops2);
        }
        flag = true;
        for(int i = 0; i < n; i++){
            if(nums[(k+i)%n] != (n-i)%n){
                flag = false;
                break;
            }
        }
        if(flag) {
            // now we can reverse the array and then cal new pos of 0
            // reversing will make the array inc which is wanted in the question
            int np = n-1-k;
            int ops1 = 1+np;
            // bring 0 to end through rotation and than reverse
            int ops2 = k+1+1;
            return min(ops1,ops2);
        }
        return -1;
    }
};