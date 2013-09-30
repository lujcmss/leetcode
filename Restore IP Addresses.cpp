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
    vector<string> re;
    
    void dfs(string &s, int pos, int deep, string tmp) {
        if (deep == 3) {
            if (s.length() - pos > 3 || pos >= s.length()) return;
            if (pos + 1 != s.length() && s[pos] == '0') return;
                
            int x = 0;
            string t = "";
            for (int i = pos; i < s.length(); i++) {
                x = x * 10 + s[i] - '0';
                t += s[i];
            }
            
            if (x < 256) {
                tmp.append(t);
                re.push_back(tmp);
            }
            return;
        }
        
        int x = 0;
        string t = "";
        for (int i = pos; i < min(pos+3, (int)s.length()); i++) {
            if (x == 0 && i != pos) continue;
            x = x * 10 + s[i] - '0';
            t += s[i];
            
            if (x < 256) dfs(s, i+1, deep+1, tmp+t+".");
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        re.clear();
        
        dfs(s, 0, 0, "");
        
        return re;
    }
};

int main() {
    string s = "";
    
    Solution so;
    vector<string> ans = so.restoreIpAddresses(s);
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    
    return 0;
}