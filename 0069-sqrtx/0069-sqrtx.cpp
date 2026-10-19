class Solution {
public:
    int mySqrt(int x){
        long long candidate=0;
        while(true){
            if(candidate*candidate<x){
                candidate++;
            }
            else if(candidate*candidate==x){
                return candidate;
            }
            else{
                return candidate-1;
            }
        }
        return candidate;
    }
};