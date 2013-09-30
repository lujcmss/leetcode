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
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (S.length() == 0 || S.length() < T.length()) return 0;
        vector<int> f(S.length());
        
        for (int i = 0; i < S.length(); i++)
            if (T[0] == S[i]) {
                if (i == 0) f[i] = 1;
                else f[i] = f[i-1] + 1;
            }
            else {
                if (i == 0) f[i] = 0;
                else f[i] = f[i-1];
            }
        
        for (int j = 1; j < T.length(); j++) {
            int last = f[j-1];
            for (int i = 0; i < j; i++) f[i] = 0;
            for (int i = j; i < S.length(); i++)
                if (T[j] == S[i]) {
                    int tmp = f[i];
                    f[i] = f[i-1] + last;
                    last = tmp;
                }
                else {
                    last = f[i];
                    f[i] = f[i-1];
                }
        }
        
        return f[S.length()-1];
    }
};

int main() {
    string s = "rabbbit";
    string t = "rabbit";
    
    Solution so;
    int ans = so.numDistinct(s, t);
    cout << ans;
}
