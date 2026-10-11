class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = 0;
        int smallestLengthstring = 201;
        string ele;
        for(int k=0; k < strs.size() ; k++){
            if(smallestLengthstring > strs[k].length()){
                smallestLengthstring = strs[k].length();
                ele = strs[k];
            }
        }
        string temp = "";
        for(int i = 0 ; i < smallestLengthstring ; i++){
            bool isfound = true;
            for(int j = 0 ; j< strs.size() ; j++){
                if(strs[j][i]==ele[i]){
                    continue;
                }else{
                    isfound = false;
                    break;
                }
            }
            if(isfound) temp+=ele[i];
            else{
                return temp;
            }
        }
        return temp;
    }
};