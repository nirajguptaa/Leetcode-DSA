class Solution {
public:
    int countVowelSubstrings(string word) {
        int n=word.size();
        int count=0;
        for(int l=0;l<n;l++){
            int a=0,e=0,iv=0,o=0,u=0;
            for(int r=l;r<n;r++){

                if(word[r]=='a'){
                    a++;
                }else if(word[r]=='e'){
                    e++;
                }else if(word[r]=='i'){
                    iv++;
                }else if(word[r]=='o'){
                    o++;
                }
                else if(word[r]=='u'){
                    u++;
                }else{
                    break;
                }
                if(a>0 && e>0 && iv>0 && o>0 && u>0){
                    count++;
                }
            }
        }
        
        return count;
    }
};