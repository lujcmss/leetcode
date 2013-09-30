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
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return "";
        string re = "1";
        
        for (int i = 1; i < n; i++) {
            string next = "";
            
            int tot = 0;
            for (int i = 0; i < re.length(); i++) {
                if (i == 0 || re[i] == re[i-1]) {
                    tot++;
                } else {
                    next += tot + '0';
                    next += re[i-1];
                    tot = 1;
                }
            }
            next += tot + '0';
            next += re[re.length()-1];
            
            re = next;
        }
        
        return re;
    }
};

int main() {
    int n = 10;
    
    Solution so;
    string ans = so.countAndSay(n);
    
    cout << ans << endl;
    
    return 0;
}