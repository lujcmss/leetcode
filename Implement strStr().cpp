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
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l1, l2;
        l1 = 0; l2 = 0;
        while (haystack[l1] != '\0') l1++;
        while (needle[l2] != '\0') l2++;
        if (l2 == 0) return haystack;
        
        vector<int> back;
        back.clear();
        back.resize(l2+1);
        
        int p;
        
        p = 0;
        back[1] = 0;
        for (int i = 2; i <= l2; i++) {
            while (p > 0 && needle[p] != needle[i-1]) p = back[p];
            if (needle[p] == needle[i-1]) p++;
            back[i] = p;
        }
        
        p = 0;
        bool flag = false;
        int offSet = 0;
        for (int i = 0; i < l1; i++) {
            while (p > 0 && needle[p] != haystack[i]) p = back[p];
            if (needle[p] == haystack[i]) p++;
            if (p == l2) {
                flag = true;
                offSet = i - l2 + 1;
                break;
            }
        }
        
        if (flag) return haystack + offSet;
        return NULL;
    }
};

int main() {
    char a[20] = "mississippi";
    char b[20] = "issip";
    
    Solution so;
    char *ans = so.strStr(a, b);
    
    if (ans != NULL) cout << ans << endl;
    
    return 0;
}