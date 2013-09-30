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
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string now, last;
        
        last.clear();
        now.clear();
        while (s[0] != '\0') {
            if (s[0] == ' ') {
                if (now != "") last = now;
                now.clear();
            } else {
                now += s[0];
            }
            s++;
        }
        if (now != "") last = now;
        
        return (int)last.length();
    }
};

int main() {
    char s[20] = "  ";
    
    Solution so;
    int ans = so.lengthOfLastWord(s);
    
    cout << ans;
    
    return 0;
}