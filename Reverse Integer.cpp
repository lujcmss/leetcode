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
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int flag;
        if (x >= 0) flag = 1;
        else flag = -1;
        x = abs(x);
        
        long long t = 0;
        while (x) {
            t = t * 10 + x % 10;
            x /= 10;
        }
        
        if (t > 2147483647 || (flag == -1 && t == -2147483648)) return 2147483647;
        if (t < -2147483648) return -2147483648;
        return flag * (int)t;
    }
};

int main() {
    
    Solution so;
    int ans = so.reverse(-123);
    
    cout << ans << endl;
    
    return 0;
}