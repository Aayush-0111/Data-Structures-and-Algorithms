class EventManager {
public:
    priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
    unordered_map<int,int> mp;
    EventManager(vector<vector<int>>& events) {
        for(int i = 0; i < (int)events.size(); i++){
            mp[events[i][0]] = events[i][1];
            pq.push(make_pair(events[i][1],-events[i][0]));
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        pq.push(make_pair(newPriority,-eventId));
        mp[eventId] = newPriority;
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto [priority,event] = pq.top();
            event = -event;
            pq.pop();
            if(mp.count(event) && priority == mp[event]){
                mp.erase(event);
                return event;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */