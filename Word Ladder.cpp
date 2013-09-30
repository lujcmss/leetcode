#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<string> > lay;
    vector<set<string> > cango;
    map<string, int> name;
    vector<int> used;
    vector<string> tmp;
    int ans;
    
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<string> list;
        list.clear();
        list.push_back(start);
        
        if (dict.count(start) != 0) dict.erase(start);
        if (dict.count(end) == 0) dict.insert(end);
        
        name.clear();
        int n = 0;
        name.insert(make_pair(start, n++));
        for (unordered_set<string>::iterator i = dict.begin(); i != dict.end(); i++)
            name.insert(make_pair(*i, n++));
        
        lay.clear(); lay.resize(dict.size()+2);
        lay[0].push_back(start);
        
        int last = 0, top = 1, layer = 1, layernum = 1;
        used.clear(); used.resize(n+1);
        cango.clear(); cango.resize(n+1);
        ans = 0;
        while (last < top) {
            string now = list[last++];
            if (used[name[end]]) break;
            
            bool flag = false;
            if (last == layer) flag = true;
            
            int len = (int)now.length();
            for (int i = 0; i < len; i++)
                for (char c = 'a'; c <='z'; c++)
                    if (now[i] != c){
                        string tmp = now;
                        tmp[i] = c;
                        
                        if (dict.count(tmp) == 0) continue;
                        if (!used[name[tmp]]) {
                            list.push_back(tmp); top++;
                            lay[layernum].push_back(tmp);
                            used[name[tmp]] = 1;
                            if (tmp == end) ans = layernum;
                        }
                        cango[name[now]].insert(tmp);
                    }
            if (flag) {
                layer = top;
                layernum++;
            }
        }
        
        if (ans == 0) return 0;
        else return ans+1;
    }
};

int main() {
    unordered_set<string> dict;
    dict.clear();
    dict.insert("hot");
    //dict.insert("dot");
    dict.insert("dog");
    //dict.insert("lot");
    //dict.insert("log");
    
    Solution so;
    int ans = so.ladderLength("dog", "hot", dict);
    cout << ans;
}
