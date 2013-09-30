#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> st;
        while (!st.empty()) st.pop();
        
        bool flag = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                if (st.empty()) flag = false;
                else {
                    char ch = st.top();
                    st.pop();
                    
                    if (ch != '(') flag = false;
                }
            } else if (s[i] == ']') {
                if (st.empty()) flag = false;
                else {
                    char ch = st.top();
                    st.pop();
                    
                    if (ch != '[') flag = false;
                }
            } else if (s[i] == '}') {
                if (st.empty()) flag = false;
                else {
                    char ch = st.top();
                    st.pop();
                    
                    if (ch != '{') flag = false;
                }
            }
        }
        if (!st.empty()) flag = false;
        
        return flag;
    }
};

int main() {
    string s = "{}[][][[{{}}]]())";
    
    Solution so;
    bool ans = so.isValid(s);
    
    cout << ans << endl;
    
    return 0;
}