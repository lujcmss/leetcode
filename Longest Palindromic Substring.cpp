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
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string t = "#";
        for (int i = 0; i < s.length(); i++) {
            t += s[i];
            t += "#";
        }
        vector<int> f(t.length()+1);
        int center = 0;
        int right = 0;
        int maxn = 0;
        int index = 0;
        
        for (int i = 0; i < t.length(); i++) {
            if (f[2 * center - i] + i < right) {
                f[i] = f[2 * center - i];
            } else {
                int j = right;
                while (j < t.length() && j <= 2 * i && t[j] == t[2 * i - j]) j++;
                f[i] = j - i;
                
                center = i;
                right = j;
                
                if (f[i] > maxn) {
                    maxn = f[i];
                    index = i;
                }
            }
        }
        
        return s.substr(index / 2 - (maxn - 1) / 2, maxn - 1);
        
        /*  TLE...
        vector<vector<int> > f;
        string t = "";
        for (int i = 0; i < s.length(); i++) t = s[i] + t;
        
        f.clear();
        f.resize(2, vector<int>(s.length()+1));
                 
        int maxn = 0;
        int index = 0;
        
        for (int i = 1; i <= s.length(); i++)
            for (int j = 1; j <= t.length(); j++)
                if (s[i-1] == t[j-1]){
                    f[i&1][j] = f[(i&1)^1][j-1] + 1;
                    if (f[i&1][j] > maxn) {
                        maxn = f[i&1][j];
                        index = i - f[i&1][j];
                    }
                }
                else f[i&1][j] = 0;
        
        return s.substr(index, maxn);
        */
        
        /*  MLE...
        vector<vector<int> > f(s.length()+1, vector<int>(s.length()+1));
        
        int maxn = 0;
        int index = 0, len = (int)s.length();
        for (int l = 0; l <= s.length(); l++) {
            for (int i = 0; i + l <= s.length(); i++) {
                int j = i + l;
                if (l <= 1) f[i][j] = 1;
                else if (f[i+1][j-1] && s[i] == s[j-1]) {
                    f[i][j] = 1;
                    if (j - i > maxn) {
                        maxn = j - i;
                        index = i;
                        len = l;
                    }
                }
                else f[i][j] = 0;
            }
        }
        
        return s.substr(index, len);
        */
    }
};

int main() {
    string s = "tta";
    
    Solution so;
    string ans = so.longestPalindrome(s);
    
    cout << ans << endl;
    
    return 0;
}