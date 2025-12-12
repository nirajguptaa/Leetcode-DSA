class Solution {
public:
    void inc(vector<int>& ans, string timestamp, string str,
             vector<int>& relax) {
        int time=stoi(timestamp);
        
        if (str == "ALL") {
            for (int i = 0; i < ans.size(); i++) {
                ans[i]++;
            }
            return;
        }

        if (str == "HERE") {
            for (int i = 0; i < relax.size(); i++) {
                if (relax[i] <= time) {
                    ans[i]++;
                }
            }
            return;
        }
        stringstream ss(str);
        string token;
        while (ss >> token) {
            if (token.size() >= 2 && token.substr(0, 2) == "id") {
                int node = stoi(token.substr(2));
                ans[node]++;
            }
        }
    }
    void off(string timestamp, string msg, vector<int>& relax) {
        int node = stoi(msg);
        relax[node] = stoi(timestamp) + 60;
    }

    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        vector<int> relax(numberOfUsers, 0);
        vector<int> ans(numberOfUsers, 0);
        auto cmp=[&](const vector<string>&a,const vector<string>&b){
            int t1=stoi(a[1]);
            int t2=stoi(b[1]);
            if(t1!=t2){
                return t1<t2;
            }
            return a[0]=="OFFLINE";
        };
        stable_sort(events.begin(),events.end(),cmp);
        for(auto &e:events){
            string type=e[0];
            string ts=e[1];
            string msg=e[2];
            int timestamp=stoi(ts);
            if(type=="OFFLINE"){
                off(ts, msg, relax);
            }else{
                inc(ans, ts, msg, relax);
            }
        }
        
        return ans;
    }
};