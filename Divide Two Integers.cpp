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
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (dividend == 0) return 0;
        
        int flag1, flag2;
        if (dividend < 0) flag1 = -1;
        else flag1 = 1;
        if (divisor < 0) flag2 = -1;
        else flag2 = 1;
        
        long long dend = dividend;
        dend = abs(dend);
        long long dsor = divisor;
        dsor = abs(dsor);
        string s = to_string(dend);
        
        long long re;
        long long x;
        
        x = re = 0;
        while (s.length() > 0) {
            x = 10 * x + s[0] - '0';
            s = s.substr(1);
            
            int y = 0;
            while (x >= dsor) {
                x -= dsor;
                y++;
            }
            re = 10 * re + y;
        }
        
        return int(re * flag1 * flag2);
    }
};

int main() {
  
    Solution so;
    int ans = so.divide(-2147483648, -2147483648);
    
    cout << ans << endl;
    
    return 0;
}