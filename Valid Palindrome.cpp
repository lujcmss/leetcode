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
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        while (i < s.length())
            if (s[i] >= 'A' && s[i] <= 'Z') s[i++] += 'a' - 'A';
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) i++;
            else s = s.erase(i, 1);
        
        for (int i = 0; i < s.length()/2; i++)
            if (s[i] != s[s.length()-1-i]) return false;
        
        return true;
    }
};

int main() {
    string s = "a,b,.";
    
    Solution so;
    bool ans = so.isPalindrome(s);
    
    cout << ans << endl;
    
    return 0;
}