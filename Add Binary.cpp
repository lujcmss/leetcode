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
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (a.length() < b.length()) {
            string tmp = a;
            a = b;
            b = tmp;
        }
        string re = "";
        
        int flag = 0;
        for (int i = (int)b.length()-1; i >= 0; i--) {
            if (a[i+a.length()-b.length()] == '1' && b[i] == '1') {
                if (flag) re = "1" + re;
                else re = "0" + re;
                flag = 1;
            } else if (a[i+a.length()-b.length()] == '0' && b[i] == '0') {
                if (flag) re = "1" + re;
                else re = "0" + re;
                flag = 0;
            } else {
                if (flag) re = "0" + re;
                else re = "1" + re;
            }
        }
        
        for (int i = (int)(a.length()-b.length()-1); i >= 0; i--) {
            if (a[i] == '1') {
                if (flag) re = "0" + re;
                else re = "1" + re;
            } else {
                if (flag) re = "1" + re;
                else re = "0" + re;
                flag = 0;
            }
        }
        
        if (flag) re = "1" + re;
        
        return re;
    }
};

int main() {
    string a = "111111";
    string b = "1";
    
    Solution so;
    string ans = so.addBinary(a, b);
    
    cout << ans << endl;
    
    return 0;
}