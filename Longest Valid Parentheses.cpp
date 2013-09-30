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
        vector<int> pa;
        pa.clear();
        
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '(') {
                pa.push_back(-2);
            } else {
                if (i == 0) {
                    pa.push_back(-2);
                } else if (s[i-1] == '(') {
                    pa.push_back(i-1);
                    pa[i-1] = i-2;
                } else {
                    int tmp = i-1;
                    while (tmp >= 0 && pa[tmp] != -2) {
                        tmp = pa[pa[tmp]];
                    }
                    if (tmp == -1) pa.push_back(-2);
                    else if (s[tmp] == '(') {
                        pa.push_back(tmp);
                        pa[tmp] = tmp-1;
                    } else {
                        pa.push_back(-2);
                    }
                }
            }
        
        int maxn;
        int r;
        
        r = (int)s.length()-1;
        maxn = 0;
        while (r > 0) {
            if (s[r] == '(') {
                r--;
                continue;
            }
            int l = r;
            while (l >= 0 && pa[l] != -2) {
                l = pa[pa[l]];
            }
            maxn = max(maxn, r - l);
            
            r = l - 1;
        }
        
        return maxn;
    }
};

int main() {
    string s = "())";
    
    Solution so;
    int ans = so.longestValidParentheses(s);
    
    cout << ans << endl;
    
    return 0;
}