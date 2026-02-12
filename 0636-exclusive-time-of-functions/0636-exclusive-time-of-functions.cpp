class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int>st;
        vector<int>ans(n,0);
        int prevTime=0;
        for(string log:logs){
            int p1=log.find(':');
            int p2=log.find(':',p1+1);
            string type=log.substr(p1+1,p2-p1-1);
            int id=stoi(log.substr(0,p1));
            int time=stoi(log.substr(p2+1));
            if(type=="start"){
                if(!st.empty()){

                    ans[st.top()]+=time-prevTime;
                }
                st.push(id);
                prevTime=time;
            }else{
                ans[st.top()]+=time-prevTime+1;
                st.pop();
                prevTime=time+1;
            }
            

        }
        return ans;

    }
};