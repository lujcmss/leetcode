#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int minCut(string s) {
        int sl = (int)s.length();
        vector<vector<int> > f(sl+1, vector<int>(sl+1));
        vector<int> dp(sl);
        
        for (int i = 0; i < sl; i++) dp[i] = sl;
        dp[0] = 0;
        for (int i = 1; i < sl; i++) {
            dp[i] = dp[i-1]+1;
            for (int j = 0; j < i; j++)
                if (s[j] == s[i] && (j+2 >= i || f[j+1][i-1])) {
                    if (j == 0) dp[i] = 0;
                    else dp[i] = min(dp[i], dp[j-1]+1);
                    f[j][i] = 1;
                }
        }
        
        return dp[sl-1];
    }
};

int main() {
    string s="aab";
    Solution so;
    int ans = so.minCut(s);
    cout << ans;
}
