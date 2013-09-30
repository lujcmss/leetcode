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
    bool check(string s, int situ) {
        if (s.length() > 0 && (s[0] == '+' || s[0] == '-')) s = s.substr(1);
        if (s.length() == 0) return false;
        
        if (s.find(".") == -1 || situ == 1) {
            for (int i = 0; i < s.length(); i++)
                if (s[i] > '9' || s[i] < '0') return false;
            return true;
        } else {
            if (s.find(".") == 0 && s.find(".") == s.length()-1) return false;
            
            for (int i = 0; i < (int)s.find("."); i++)
                if (s[i] > '9' || s[i] < '0') return false;
            
            for (int i = (int)s.find(".")+1; i < s.length(); i++)
                if (s[i] > '9' || s[i] < '0') return false;
            
            return true;
        }
    }
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string num = s;
        
        while(num.length() > 0 && num[0] == ' ') num = num.substr(1);
        while(num.length() > 0 && num[num.length()-1] == ' ') num = num.substr(0, num.length()-1);
        
        if (num.length() > 0 && (num[0] == '+' || num[0] == '-')) num = num.substr(1);
        if (num.substr(0, 2) == "0X" || num.substr(0, 2) == "0x")
            num = num.substr(2);
        if (num.length() == 0) return false;
        
        bool flag;
        if (num.find("e") != -1) {
            flag = (check(num.substr(0, num.find("e")), 0) && check(num.substr(num.find("e")+1), 1));
        } else if (num.find("E") != -1) {
            flag = (check(num.substr(0, num.find("E")), 0) && check(num.substr(num.find("E")+1), 1));
        } else {
            num = "+" + num;
            flag = check(num, 0);
        }
        
        return flag;
    }
};

int main() {
    char s[20] = "2e.3";
    
    Solution so;
    bool ans = so.isNumber(s);
    
    cout << ans << endl;
    
    return 0;
}