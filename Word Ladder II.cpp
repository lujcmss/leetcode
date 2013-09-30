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
    vector<vector<string> > re;
    vector<string> tmp;
    map<string, vector<string> > pre;
    unordered_set<string> next[2];
    
    void dfs(string now, string &start) {
        tmp.insert(tmp.begin(), now);
        
        if (now == start) {
            re.push_back(tmp);
            return;
        }
        
        for (int i = 0; i < pre[now].size(); i++) {
            dfs(pre[now][i], start);
            tmp.erase(tmp.begin());
        }
    }
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        re.clear();
        pre.clear();
        next[0].clear(); next[1].clear();
        
        if (dict.count(start)) dict.erase(start);
        dict.insert(end);
        next[0].insert(start);
        
        int flag = 0;
        int len = (int)start.length();
        while (true) {
            if (next[flag].size() == 0) return re;
            
            for (unordered_set<string>::iterator i = next[flag].begin(); i != next[flag].end(); i++) {
                dict.erase(*i);
            }
            next[flag^1].clear();
            
            for (unordered_set<string>::iterator i = next[flag].begin(); i != next[flag].end(); i++)
                for (int j = 0; j < len; j++)
                    for (char c = 'a'; c <= 'z'; c++) {
                        string os = *i, ts = *i;
                        ts[j] = c;
                        if (os == ts) continue;
                        
                        if (dict.count(ts)) {
                            next[flag^1].insert(ts);
                            pre[ts].push_back(os);
                        }
                    }
            
            if (next[flag^1].count(end)) break;
            flag ^= 1;
        }
        
        tmp.clear();
        dfs(end, start);
        
        return re;
    }
};

int main() {
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    
    Solution so;
    vector<vector<string> > ans = so.findLadders("hit", "cog", dict);
    
    for (int i = 0; i < ans.size(); i++, cout << endl)
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
    
    return 0;
}