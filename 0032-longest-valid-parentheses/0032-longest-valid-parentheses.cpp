// // kinda two pointer approach
// // 1. Traverse left to right and count '(' in l and ')' in r.
// // 2. If l == r, update ans with 2*r (we found a valid substring).
// // 3. If r > l, reset both counters because closing brackets are unmatched.
// // 4. Traverse right to left and reset if l > r, to handle extra '('.
// // 5. Update ans whenever l == r and return the maximum length found.
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int l = 0, r = 0, n = s.size(), ans = 0;
//         for(int i = 0; i < n; i++) {
//             if(s[i] == '(') l++;
//             else r++;
//             if(l == r) ans = max(ans, 2 * r);
//             else if(r > l) l = r = 0;
//         }
//         l = r = 0;
//         for(int j = n - 1; j >= 0; j--) {
//             if(s[j] == '(') l++;
//             else r++;
//             if(l == r) ans = max(ans, 2 * l);
//             else if(l > r) l = r = 0;
//         }
//         return ans;
//     }
// };
//Stack approach

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();

                if(st.empty()) {
                    st.push(i);
                }
                else {
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};

