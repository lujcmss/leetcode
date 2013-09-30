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
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        const char *star = NULL;
        const char *ts = s;
        
        while (*s) {
            if (*p == '?' || *s == *p) {
                s++; p++;
            } else if (*p == '*') {
                star = p++;
                ts = s;
            } else {
                if (star == NULL) return false;
                s = ++ts;
                p = star+1;
            }
        }
        
        while (*p && *p == '*') p++;
        if (!*p) return true;
        return false;
    }
};

int main() {
    char s[10] = "adsf";
    char p[10] = "a*?";
    
    Solution so;
    bool ans = so.isMatch(s, p);
    
    cout << ans << endl;
    
    return 0;
}