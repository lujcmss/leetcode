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
    map<char, int> ma;
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ma.clear();
        int re = 0;
        int i = 0, j = 0;
        int tmp = 1;
        
        while (i < s.length()) {
            tmp--;
            while (i < s.length() && (ma.count(s[i]) == 0 || ma[s[i]] == 0)) {
                tmp++;
                ma[s[i++]]++;
            }
            re = max(re, tmp);
            ma[s[j++]]--;
        }
        
        return re;
    }
};

int main() {
    string s = "abbbcde";
    
    Solution so;
    int ans = so.lengthOfLongestSubstring(s);
    
    cout << ans << endl;
    
    return 0;
}