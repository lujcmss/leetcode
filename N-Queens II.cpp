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
    int maxn;
    int tot;
    
    void dfs(int deep, int row, int lcor, int rcor) {
        if (deep == 0) {
            tot++;
            return;
        }
        
        int can = (~(row | lcor | rcor) & ((1<<maxn)-1));
        while (can) {
            int pos = (can & -can);
            dfs(deep-1, row|pos, (lcor|pos)>>1, (rcor|pos)<<1);
            can -= pos;
        }
    }
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        tot = 0;
        
        maxn = n;
        dfs(n, 0, 0, 0);
        
        return tot;
    }
};

int main() {
    int n = 14;
    
    Solution so;
    int ans = so.totalNQueens(n);
    
    cout << ans << endl;
    
    return 0;
}