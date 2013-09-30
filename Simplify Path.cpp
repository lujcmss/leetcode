#include <stdio.h>
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
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string re = "";
        if (path.length() == 0) return re;
        
        int l = 0;
        while (l < path.length()) {
            int r = l+1;
            while (r < path.length() && path[r] != '/') r++;
            
            string tmp = path.substr(l+1, r - l - 1);
            if (tmp == "..") {
                if (re.find_last_of("/") != -1) re.erase(re.find_last_of("/"));
            } else if (tmp != "" && tmp != ".") {
                re += "/" + tmp;
            }
            l = r;
        }
        if (re.length() == 0) re += "/";
        
        return re;
    }
};

int main() {
    string path = "//../../a/./b/../../c//..//";
    
    Solution so;
    string ans = so.simplifyPath(path);
    
    cout << ans << endl;
    
    return 0;
}