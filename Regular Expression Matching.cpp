#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    bool dfs(const char *s, const char *p, int l1, int l2) {
        if (p[l2] == '\0') return (s[l1] == '\0') ? true : false;
        
        if (p[l2 + 1] == '*') {
            int j = l1;
            
            while (s[j] != '\0' && (p[l2] == '.' || s[j] == s[l1])) {
                int flag = dfs(s, p, j, l2 + 2);
                if (flag) return true;
                if (s[l1] == p[l2] || p[l2] == '.') j++;
                else break;
            }
            
            return dfs(s, p, j, l2 + 2);
        } else {
            if (s[l1] != '\0' && (p[l2] == '.' || s[l1] == p[l2])) return dfs(s, p, l1 + 1, l2 + 1);
            return false;
        }
    }
    
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return dfs(s, p, 0, 0);
    }
};

int main() {
    char s[20] = "";
    char p[20] = "a*";
    
    Solution so;
    int ans = so.isMatch(s, p);
    
    cout << ans << endl;
    
    return 0;
}