// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int l = 0 , r = 0 , n= s.size();
//         int i;
        
//         for(i = 0 ; i< n;i++){
//             if(s[i]=='('){
//                 break;
//             }
//         }
//         int j;
//         for(j= n-1 ; j> 0;j--){
//             if(s[j]==')'){
//                 break;
//             }
//         }
//         if(i>j){
//             return 0;
//         }
//         return j - i +1;
//     }
// };

class Solution {
public:
    int longestValidParentheses(string s) {
        int l = 0, r = 0, n = s.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') l++;
            else r++;
            if(l == r) ans = max(ans, 2 * r);
            else if(r > l) l = r = 0;
        }
        l = r = 0;
        for(int j = n - 1; j >= 0; j--) {
            if(s[j] == '(') l++;
            else r++;
            if(l == r) ans = max(ans, 2 * l);
            else if(l > r) l = r = 0;
        }
        return ans;
    }
};
