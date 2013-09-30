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
    map<string, int> m;
    map<string, int> count;
    vector<int> re;
    int n;
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        m.clear();
        count.clear();
        re.clear();
        n = 0;
        
        if (L.size() == 0) return re;
        
        for (int i = 0; i < L.size(); i++) {
            if (!m.count(L[i])) m[L[i]] = n++;
            count[L[i]]++;
        }
        
        int *a = new int[n];
        
        int len = (int)L[0].length();
        for (int k = 0; k < len; k++) {
            memset(a, 0, sizeof(a)*n);
            int now = k;
            int tot = 0;
            int totValid = 0;
            
            while (now + len <= S.length()) {
                string tmp = S.substr(now, len);
                if (m.count(tmp)) {
                    a[m[tmp]]++;
                    tot++;
                    if (a[m[tmp]] == count[tmp]) totValid++;
                    if (a[m[tmp]] == count[tmp] + 1) totValid--;
                    
                    if (totValid == n) re.push_back(now - ((int)L.size() - 1) * len);
                    if (tot == L.size()) {
                        string last = S.substr(now - ((int)L.size() - 1) * len, len);
                        a[m[last]]--;
                        tot--;
                        
                        if (a[m[last]] == count[last]) totValid++;
                        if (a[m[last]] == count[last] - 1) totValid--;
                    }
                } else {
                    memset(a, 0, sizeof(a)*n);
                    tot = 0;
                    totValid = 0;
                }
                now += len;
            }
        }
        return re;
    }
};

int main() {
    string s = "barfoofoothefooarfoo";
    vector<string> l;
    l.push_back("foo");
    l.push_back("foo");
    
    Solution so;
    vector<int> ans = so.findSubstring(s, l);
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    
    return 0;
}