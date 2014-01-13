#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <tr1/unordered_set>
#include <map>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
using namespace std::tr1;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int maxn = 0;
        for (unordered_set<string>::iterator i = dict.begin(); i != dict.end(); i++) {
            string t = *i;
            maxn = max(maxn, (int)t.length());
        }
        
        vector<int> f;
        f.clear();
        f.resize(s.length()+1);
        f[0] = 1;
        for (int i = 1; i <= s.length(); i++)
            for (int j = 0; j < min(maxn, i); j++)
                if (f[i - j - 1]) {
                    string t = s.substr(i - j - 1, j + 1);
                    if (dict.count(t)) {
                        f[i] = 1;
                        break;
                    }
                }
        
        return f[s.length()];
    }
};

int main() {
    string s = "leetcode";
    unordered_set<string> dict;
    dict.clear();
    dict.insert("leet");
    dict.insert("code");
    
    Solution so;
    bool ans = so.wordBreak(s, dict);
    
    cout << ans << endl;
    
    return 0;
}