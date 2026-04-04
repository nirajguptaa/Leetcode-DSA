class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len=encodedText.size();
        int col=len/rows;
        string ans="";
        for(int c=0;c<col;c++){
            int j=c,i=0;
            
            while(i<rows && j<col){
                ans+=encodedText[i*col+j];
                i++;
                j++;
            }
            

         
        }
        while(!ans.empty() && ans.back()==' '){
            ans.pop_back();
            
        }
        return ans;
    }
};