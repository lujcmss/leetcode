#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    map<char, int> ma;
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ma.clear();
        ma['I'] = 1;
        ma['V'] = 5;
        ma['X'] = 10;
        ma['L'] = 50;
        ma['C'] = 100;
        ma['D'] = 500;
        ma['M'] = 1000;
        
        int num = 0;
        int maxn = 0;
        for (int i = (int)s.length()-1; i >= 0; i--) {
            if (maxn > ma[s[i]]) num -= ma[s[i]];
            else num += ma[s[i]];
            maxn = max(maxn, ma[s[i]]);
        }
        
        return num;
    }
};

int main() {
    string s = "MCMLIV";
    
    Solution so;
    int ans = so.romanToInt(s);
    
    cout << ans << endl;
    
    return 0;
}