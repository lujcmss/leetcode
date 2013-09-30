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
    vector<int> tmp;
    vector<vector<int> > re;
    
    void dfs(vector<int> s, int pos) {
        if (pos == s.size()) {
            re.push_back(tmp);
            return;
        }
        
        int x = pos;
        while (x < s.size() && s[x] == s[pos]) x++;
        
        for (int i = 0; i <= x-pos; i++) {
            for (int j = 0; j < i; j++) tmp.push_back(s[pos]);
            dfs(s, x);
            for (int j = 0; j < i; j++) tmp.pop_back();
        }
    }
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        tmp.clear(); re.clear();
        
        sort(S.begin(), S.end());
        dfs(S, 0);
        
        return re;
    }
};

int main() {
    vector<int> s;
    s.clear();
    s.push_back(1); s.push_back(2); s.push_back(2);
    
    Solution so;
    vector<vector<int> > ans = so.subsetsWithDup(s);
    
    for (int i = 0; i < ans.size(); i++, cout << endl)
        for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
    
    return 0;
}