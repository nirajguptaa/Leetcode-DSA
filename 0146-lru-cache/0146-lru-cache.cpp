class LRUCache {
public:
    int cap;
    list<pair<int,int>>dll;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        auto node=mp[key];
        int val=node->second;
        dll.erase(node);
        dll.push_front({key,val});
        mp[key]=dll.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            dll.erase(mp[key]);
        }
        dll.push_front({key,value});
        mp[key]=dll.begin();
        if(dll.size()>cap){
            auto last=dll.back();
            int keyTodel=last.first;
            mp.erase(keyTodel);
            dll.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */