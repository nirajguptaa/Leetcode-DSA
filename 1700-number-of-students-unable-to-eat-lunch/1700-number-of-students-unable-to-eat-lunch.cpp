class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }
        int i=0;
        int n=sandwiches.size();
        int failed=0;
        while(i<n){
            if(q.front()==sandwiches[i]){
                q.pop();
                i++;
                failed=0;
            }else{
                int ele=q.front();
                q.pop();
                q.push(ele);
                failed++;
            }
            if (failed == q.size()) break;
            
        }
        return q.size();
            
    }
};