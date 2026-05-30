class LFUCache {
public:
    int cap;
    int minFreq;
    unordered_map<int,int>keyValue;//key value
    unordered_map<int,int>keyFreq;//key freq
    unordered_map<int,list<int>>freqList;//freq->list of keys
    unordered_map<int,list<int>::iterator>pos;//key -> position of that key in its frequency list
    LFUCache(int capacity) {
        cap=capacity;
        minFreq=0;
    }
    void updateFreq(int key){
        int freq=keyFreq[key];
        freqList[freq].erase(pos[key]);
        if(freq==minFreq && freqList[freq].empty()){
            minFreq++;
        }
        keyFreq[key]++;
        freqList[freq+1].push_front(key);
        pos[key]=freqList[freq+1].begin();
    }
    int get(int key) {
        if(keyValue.find(key)==keyValue.end()){
            return -1;
        }
        updateFreq(key);
        return keyValue[key];
    }
    
    void put(int key, int value) {
        if(cap==0)return ;
        if(keyValue.find(key)!=keyValue.end()){
            keyValue[key]=value;
            updateFreq(key);
            return ;
        }
        if(keyValue.size()==cap){
            int victim=freqList[minFreq].back();
            freqList[minFreq].pop_back();
            keyValue.erase(victim);
            keyFreq.erase(victim);
            pos.erase(victim);
        }
        keyValue[key]=value;
        keyFreq[key]=1;
        freqList[1].push_front(key);
        pos[key]=freqList[1].begin();
        minFreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */