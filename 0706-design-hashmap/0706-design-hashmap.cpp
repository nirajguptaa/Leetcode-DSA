class MyHashMap {
public:
    int size=1000;
    vector<list<pair<int,int>>>buckets;
    int hash(int key){
        return key%1000;
    }
    MyHashMap() {
        buckets.resize(size);
    }
    
    void put(int key, int value) {
        int idx=hash(key);
        for(auto &it:buckets[idx]){
            if(it.first==key){
                it.second=value;
                return ;
            }
        }
        buckets[idx].push_back({key,value});
    }
    
    int get(int key) {
        int idx=hash(key);
        for(auto &it:buckets[idx]){
            if(it.first==key){
                return it.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx=hash(key);
        auto &bucket=buckets[idx];
        for(auto it=bucket.begin();it!=bucket.end();it++){
            if(it->first==key){
                bucket.erase(it);
                return ;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */