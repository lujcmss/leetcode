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
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() == 0 || s[0] == '0') return 0;
        
        int flag = true;
        vector<int> f;
        f.clear();
        f.push_back(1); f.push_back(1);
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '0') {
                if (s[i-1] > '2' || s[i-1] == '0') flag = false;
                else f.push_back(f[i-1]);
            }
            else if (s[i-1] == '1') f.push_back(f[i]+f[i-1]);
            else if (s[i-1] == '2' && s[i] <= '6') f.push_back(f[i]+f[i-1]);
            else f.push_back(f[i]);
        }
        
        return flag ? f[f.size()-1] : 0;
    }
};

int main() {
    string s = "130";
    
    Solution so;
    int ans = so.numDecodings(s);
    
    cout << ans << endl;
    
    return 0;
}