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
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> re = digits;
        re[re.size()-1]++;
        for (int i = (int)re.size()-1; i > 0; i--)
            if (re[i] > 9) {
                re[i] %= 10;
                re[i-1]++;
            }
        if (re[0] > 9) {
            re[0] %= 10;
            re.insert(re.begin(), 1);
        }
        
        return re;
    }
};

int main() {
    vector<int> digits;
    digits.push_back(8);
    digits.push_back(9);
    digits.push_back(9);
    
    Solution so;
    vector<int> ans = so.plusOne(digits);
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    
    return 0;
}