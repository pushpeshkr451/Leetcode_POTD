// Last updated: 09/06/2026, 19:42:58
class EventManager {
public:

    unordered_map<int,int>mp;
    priority_queue<pair<int,int>>pq;
    
    EventManager(vector<vector<int>>& events) {
        for(auto &it:events){
            int id=it[0];
            int pr=it[1];
            mp[id]=pr;
            pq.push({pr,-id});
        }
    }
    
    void updatePriority(int a, int b) {
        mp[a]=b;
        pq.push({b,-a});
        
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto [pr,nid]=pq.top();
            int id=-nid;

            pq.pop();

            if(mp.count(id)&&mp[id]==pr){
                mp.erase(id);
                return id;
            }
            
        }return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */