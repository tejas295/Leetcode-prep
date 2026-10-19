class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int wordCount=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==' ' && wordCount!=0){
                break;
            }
            else if(s[i]!=' '){
                wordCount++;
            }
        }
        return wordCount;
    }
};