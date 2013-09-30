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
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strs.size() == 0) return "";
        
        string longest = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            string tmp = strs[i];
            int l = 0;
            while (l < longest.length() && l < tmp.length()) {
                if (longest[l] == tmp[l]) l++;
                else break;
            }
            longest = longest.substr(0, l);
        }
        
        return longest;
    }
};

int main() {
    vector<string> strs;
    strs.push_back("asdfgh");
    strs.push_back("bsdf");
    strs.push_back("asddffgh");
    strs.push_back("asdfgh");
    
    Solution so;
    string ans = so.longestCommonPrefix(strs);
    
    cout << ans << endl;

    return 0;
}