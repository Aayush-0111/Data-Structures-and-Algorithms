class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        // do the most demanding job first
        // what makes it most demanding is the gap b/w Required and Minimum
        // see if diff b/w Req and Min for A is larger than B
        // that means, A REQ MORE ENERGY BUT DOES NOT DRAIN THAT MUCH
        // whereas B REQ LESS ENERGY BUT IT WILL DRAIN MORE ENERY AFTER THE WORK AS COMPARED TO A
        // A->[10,12], B -> [2,4]
        // B might look less work, but it require twice the amount it needs
        // While A might look big, but it requires only 1 extra unit of work
        // and Since we will be doing all the task, we have to consume the minimum energy anyways
        // so finish the work which are more demanding a.k.a the work where gap b/w min. and req. is larger. 
        vector<vector<int>> jobs(n,vector<int>(2,0)); 
        int total = 0;
        for(int i = 0; i < n; i++){
            jobs[i][0] = tasks[i][1] - tasks[i][0];
            jobs[i][1] = i;
            total += tasks[i][0];
        }
        int ans = total;
        sort(jobs.begin(),jobs.end(),[&](auto& a, auto& b){
            if(a[0] == b[0]){
                return tasks[a[1]][0] < tasks[b[1]][0];
            }
            return a[0] > b[0];
        });
        for(int i = 0; i < n; i++){
            int idx = jobs[i][1];
            if(total < tasks[idx][1]){
                int diff = tasks[idx][1] - total;
                ans += diff;
                total += diff;
            }
            total -= tasks[idx][0];
        }
        return ans;
    }
};