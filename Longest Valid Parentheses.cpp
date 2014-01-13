#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int re = 0;
        stack<int> st;
        while (!st.empty()) st.pop();
        
        int last = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') st.push(i);
            else {
                if (st.empty()) last = i;
                else {
                    st.pop();
                    if (st.empty()) re = max(re, i - last);
                    else re = max(re, i - st.top());
                }
            }
        }
        
        return re;
    }
};

int main() {
    string s = "())";
    
    Solution so;
    int ans = so.longestValidParentheses(s);
    
    cout << ans << endl;
    
    return 0;
}