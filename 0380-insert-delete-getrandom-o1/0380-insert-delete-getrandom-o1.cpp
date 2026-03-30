class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!mp.count(val)){
            int x = v.size();
            mp[val] = x;
            v.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(!mp.count(val)){
            return false;
        }
        int x = mp[val];
        swap(v[x],v.back());
        v.pop_back();
        mp[v[x]] = x;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int x = v.size();
        int i = rand()%x;
        return v[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */