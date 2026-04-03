class MyHashSet {
public:
    vector<int> v;
    MyHashSet() {
        
    }
    
    void add(int key) {
        int n = v.size();
        if(key >= n){
            v.resize(key+1,-1);
        }
        v[key] = key;
    }
    
    void remove(int key) {
        if(key < (int)v.size() && v[key] != -1) v[key] = -1;
    }
    
    bool contains(int key) {
        if(key >= (int)v.size()) return false;
        return (v[key] != -1) ? true : false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */