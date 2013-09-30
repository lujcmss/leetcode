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
private:
    vector<vector<string> > re;
    vector<string> tmp;
    int maxn;
    
    void add(int pos) {
        string t = "";
        for (int i = 0; i < maxn; i++)
            if (pos&((1<<i))) t += "Q";
            else t += ".";
        tmp.push_back(t);
    }
    void dfs(int deep, int row, int lcor, int rcor) {
        if (deep == 0) {
            re.push_back(tmp);
            return;
        }
        
        int can = (~(row | lcor | rcor) & ((1<<maxn)-1));
        while (can) {
            int pos = (can & -can);
            add(pos);
            dfs(deep-1, row|pos, (lcor|pos)>>1, (rcor|pos)<<1);
            tmp.pop_back();
            can -= pos;
        }
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        re.clear();
        tmp.clear();
        
        maxn = n;
        dfs(n, 0, 0, 0);
        
        return re;
    }
};

int main() {
    int n = 0;
    
    Solution so;
    vector<vector<string> > ans = so.solveNQueens(n);
    
    for (int i = 0; i < ans.size(); i++, cout << endl)
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << endl;
    
    return 0;
}