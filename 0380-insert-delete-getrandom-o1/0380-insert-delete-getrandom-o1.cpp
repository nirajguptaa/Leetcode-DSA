class RandomizedSet {
public:
    vector<int>nums;
    unordered_map<int,int>pos;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(pos.find(val)!=pos.end()){
            return false;
        }
        int size=nums.size();
        nums.push_back(val);
        
        pos[val]=size;
        return true;
    }
    
    bool remove(int val) {
        if(pos.find(val)==pos.end()){
            return false;
        }
        int idx=pos[val];
        int last_ele=nums.back();//ele
        nums[idx]=last_ele;
        pos[last_ele]=idx;
        nums.pop_back();
        pos.erase(val);
        return true;

    }
    
    int getRandom() {

        int size=nums.size();
        int idx=rand() % size;
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */