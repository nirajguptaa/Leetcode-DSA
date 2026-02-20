class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length()<2)return true;
        bool first=true;
        if(word[0]>='a' && word[0]<='z'){
            first=false;
        }
        bool sec=true;
        if(word[1]>='a' && word[1]<='z'){
            sec=false;
        }
        if(!first && sec){
            return false;
        }
        for(int i=2;i<word.size();i++){
            if(first && !sec){
                if(word[i]>='A' && word[i]<='Z'){
                    return false;
                }
            }else if(!first){
                if(word[i]>='A' && word[i]<='Z'){
                    return false;
                }
            }else if(first && sec){
                if(word[i]>='a' && word[i]<='z'){
                    return false;
                }
            }
        }
        return true;
        
    }
};