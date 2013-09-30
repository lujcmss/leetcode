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
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) return false;
        int y = 0, t = x;
        while (t) {
            y = y * 10 + t % 10;
            t /= 10;
        }
        
        return (x == y);
    }
};

int main() {
    
    Solution so;
    bool ans = so.isPalindrome(121);
    
    cout << ans << endl;
    
    return 0;
}