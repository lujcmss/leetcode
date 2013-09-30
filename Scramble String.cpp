#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

class Solution {
private:
    bool dfs(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        if (s1.length() == 0) return true;
        
        string ts1 = s1, ts2 = s2;
        sort(ts1.begin(), ts1.end());
        sort(ts2.begin(), ts2.end());
        
        for (int i = 0; i < ts1.length(); i++)
            if (ts1[i] != ts2[i]) return false;
        if (ts1.length() == 1) return true;
        
        for (int i = 1; i < s1.length(); i++) {
            if (dfs(s1.substr(0, i), s2.substr(s1.length()-i)) &&
                dfs(s1.substr(i), s2.substr(0, s1.length()-i))) return true;
            if (dfs(s1.substr(0, i), s2.substr(0, i)) &&
                dfs(s1.substr(i), s2.substr(i))) return true;
        }
        
        return false;
    }
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        return dfs(s1, s2);
    }
};

int main() {
    string s1 = "abb";
    string s2 = "bab";
    
    Solution so;
    bool ans = so.isScramble(s1, s2);
    
    cout << ans << endl;
    return 0;
}