#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s3.length() != s1.length() + s2.length()) return false;
        
        vector<vector<int> > f(s1.length()+1);
        for (int i = 0; i < f.size(); i++)
            f[i].resize(s2.length()+1);
        
        f[0][0] = 1;
        for (int i = 0; i <= s1.length(); i++)
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 && j == 0) continue;
                if (i == 0) {
                    if (s2[j-1] == s3[j-1]) f[i][j] = f[i][j-1];
                } else if (j == 0) {
                    if (s1[i-1] == s3[i-1]) f[i][j] = f[i-1][j];
                } else {
                    if (s1[i-1] == s3[i+j-1] && f[i-1][j]) f[i][j] = 1;
                    if (s2[j-1] == s3[i+j-1] && f[i][j-1]) f[i][j] = 1;
                }
            }
        
        return f[s1.length()][s2.length()];
    }
};

int main() {
    string s1 = "abcde";
    string s2 = "54321";
    string s3 = "abc543de12";
    
    Solution so;
    bool ans = so.isInterleave(s1, s2, s3);
    
    cout << ans << endl;
    
    return 0;
}