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
private:
    vector<string> re;
    string tmp;
    int maxn;
    
    void dfs(string &s, int now, int len, unordered_set<string> &dict) {
        if (now == len) {
            re.push_back(tmp);
            return;
        }
        
        for (int i = 1; i <= maxn; i++)
            if (now + i <= len) {
                string t = s.substr(now, i);
                if (dict.count(t)) {
                    if (now) tmp += " " + t;
                    else tmp += t;
                    
                    dfs(s, now + i, len, dict);
                    
                    if (now) tmp = tmp.substr(0, tmp.length() - i - 1);
                    else tmp = tmp.substr(0, tmp.length() - i);
                }
            }
    }
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        maxn = 0;
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
        
        re.clear();
        tmp = "";
        if (!f[s.length()]) return re;
        
        dfs(s, 0, (int)s.length(), dict);
        
        return re;
    }
};

int main() {
    string s = "leetcode";
    unordered_set<string> dict;
    dict.clear();
    dict.insert("leet");
    dict.insert("code");
    dict.insert("co");
    dict.insert("de");
    dict.insert("lee");
    dict.insert("tcode");
    
    Solution so;
    vector<string> ans = so.wordBreak(s, dict);
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    
    return 0;
}