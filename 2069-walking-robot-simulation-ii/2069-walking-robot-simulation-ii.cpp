class Robot {
public:
    int x=0,y=0;
    vector<pair<int,int>>pos;
    vector<int>dir;
    int d=0;
    int Xmax=0,Ymax=0;
    int idx=0;
    bool moved=true;
    Robot(int width, int height) {
        Xmax=width;
        Ymax=height;
        for (int i = 0; i < width; i++) {
            pos.push_back({i, 0});
            dir.push_back(0); // East
        }
        for (int i = 1; i < height; i++) {
            pos.push_back({width - 1, i});
            dir.push_back(1); // North
        }
        for (int i = width - 2; i >= 0; i--) {
            pos.push_back({i, height - 1});
            dir.push_back(2); // West
        }
        for (int i = height - 2; i > 0; i--) {
            pos.push_back({0, i});
            dir.push_back(3); // South
        }
        if (!dir.empty()) dir[0] = 3;
    }
    
    void step(int num) {
        if(pos.empty())return;
        moved=true;
        idx=(idx+num)%pos.size();
        x=pos[idx].first;
        y=pos[idx].second;
        d=dir[idx];
        
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(!moved)return "East";
        if (d == 0) return "East";
        else if (d == 1) return "North";
        else if (d == 2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */