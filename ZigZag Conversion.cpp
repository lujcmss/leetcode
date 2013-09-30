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
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (nRows <= 1) return s;
        
        string re = "";
        for (int i = 0; i < nRows; i++) {
            if (i == 0 || i == nRows - 1) {
                int j = i;
                for (; j < s.length(); j += (nRows - 1) * 2) {
                    re += s[j];
                }
            } else {
                int j = i;
                int j2 = (nRows - 1) * 2 - i;
                for (; j < s.length(); j += (nRows - 1) * 2, j2 += (nRows - 1) * 2) {
                    re += s[j];
                    if (j2 < s.length()) re += s[j2];
                }
            }
        }
        
        return re;
    }
};

int main() {
    string s = "PAYPALISHIRING";
    
    Solution so;
    string ans = so.convert(s, 2);
    
    cout << ans << endl;
    
    return 0;
}