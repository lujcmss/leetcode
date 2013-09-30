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
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> n1;
        vector<int> n2;
        n1.clear(); n2.clear();
        vector<int> re(num1.size() + num2.size() + 2);
        
        for (int i = (int)num1.size()-1; i >= 0; i--)
            n1.push_back(num1[i]-'0');
        for (int i = (int)num2.size()-1; i >= 0; i--)
            n2.push_back(num2[i]-'0');
        
        for (int i = 0; i < n1.size(); i++)
            for (int j = 0; j < n2.size(); j++)
                re[i+j] += n1[i] * n2[j];
        
        for (int i = 0; i < re.size()-1; i++) {
            re[i+1] += re[i] / 10;
            re[i] %= 10;
        }
        
        while ((re.size() > 1) && re[re.size()-1] == 0) re.pop_back();
        
        string mul = "";
        for (int i = (int)re.size()-1; i >= 0; i--)
            mul.push_back(re[i]+'0');
        
        return mul;
    }
};

int main() {
    string num1 = "12345";
    string num2 = "1";
    
    Solution so;
    string ans = so.multiply(num1, num2);
    
    cout << ans << endl;
    
    return 0;
}