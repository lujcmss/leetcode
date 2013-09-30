#include <stdio.h>
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
    int a[200], b[200];
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        
        int tot = 0;
        for (int i = 0; i < T.length(); i++) {
            if (!a[T[i]]) tot++;
            a[T[i]] = 1;
            b[T[i]]++;
        }
        
        string re = "";
        int l = 0, r = 0;
        while (l < S.length()) {
            while (r < S.length() && tot) {
                if (a[S[r]] && a[S[r]] == b[S[r]]) tot--;
                if (a[S[r]]) a[S[r]]++;
                r++;
            }
            if (!tot && (re == "" || re.length() > r - l)) re = S.substr(l, r-l);
            
            if (a[S[l]] && a[S[l]] == b[S[l]]+1) tot++;
            if (a[S[l]] > 1) a[S[l]]--;
            l++;
        }
        
        return re;
    }
};

int main() {
    string s = "A";
    string t = "B";
    
    Solution so;
    string ans = so.minWindow(s, t);
    
    cout << ans << endl;
    
    return 0;
}