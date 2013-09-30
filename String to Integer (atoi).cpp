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
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while (*str == ' ') str++;
        if (str == NULL) return 0;
        
        int flag;
        if (*str == '-') flag = -1;
        else flag = 1;
        
        if (*str == '-' || *str == '+') str++;
        
        long long num = 0;
        int maxn = 2147483647;
        int minn = -2147483648;
        
        while ((*str >= '0' && *str <= '9') || *str == '.') {
            if (*str == '.') break;
            num = num * 10 + *str - '0';
            if (flag * num > maxn || flag * num < minn) break;
            str++;
        }
        
        if (flag * num > maxn) return maxn;
        if (flag * num < minn) return minn;
        return (int)num * flag;
    }
};

int main() {
    char str[20] = "2147483648";
    
    Solution so;
    int ans = so.atoi(str);
    
    cout << ans << endl;
    
    return 0;
}