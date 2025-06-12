class LRUCache {
    int cap;
    list<pair<int,int>> dq;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int c):cap(c){}
    int get(int key){
        auto it=mp.find(key);
        if(it==mp.end()) return -1;
        dq.splice(dq.end(), dq, it->second);
        return it->second->second;
    }
    void put(int key,int value){
        auto it=mp.find(key);
        if(it!=mp.end()){
            it->second->second=value;
            dq.splice(dq.end(), dq, it->second);
            return;
        }
        if(dq.size()==cap){
            mp.erase(dq.front().first);
            dq.pop_front();
        }
        dq.emplace_back(key,value);
        mp[key]=prev(dq.end());
    }
};

