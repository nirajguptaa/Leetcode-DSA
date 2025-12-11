class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,vector<int>>row,col;
        for(auto &it:buildings){
            row[it[1]].push_back(it[0]);
            col[it[0]].push_back(it[1]);
        }
        for(auto &r:row){
            sort(r.second.begin(),r.second.end());
        }
        for(auto &c:col){
            sort(c.second.begin(),c.second.end());
        }
        int count=0;
        
        // for(auto it:buildings){
        //     bool l=false,r=false,u=false,d=false;
        //     int x=it[0];
        //     int y=it[1];
        //     for(auto r:col[x]){
        //         if(r>y){
        //             u=true;
        //         }
        //         if(r<y){
        //             d=true;
        //         }
        //     }
        //     for(auto c:row[y]){
        //         if(c>x){
        //             r=true;
        //         }
        //         if(c<x){
        //             l=true;
        //         }
        //     }
        //     if(l && r && u && d){
        //         count++;
        //     }
        // }

        for(auto &b:buildings){
            int x=b[0],y=b[1];
            auto &rvec=row[y];
            auto &cvec=col[x];
            auto it=lower_bound(rvec.begin(),rvec.end(),x);
            bool left=(it!=rvec.begin());
            bool right=(it!=rvec.end()-1);
            auto it2=lower_bound(cvec.begin(),cvec.end(),y);
            bool down=(it2!=cvec.begin());
            bool up=(it2!=cvec.end()-1);
            if(left && right && up && down){
                count++;
            }
        }

        return count;


        
    }
};