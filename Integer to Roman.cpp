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
private:
    map<int, char> ma;
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ma.clear();
        ma[1] = 'I';
        ma[5] = 'V';
        ma[10] = 'X';
        ma[50] = 'L';
        ma[100] = 'C';
        ma[500] = 'D';
        ma[1000] = 'M';
        ma[5000] = '\0';
        
        string roman = "";
        int x = 1000;
        while (x) {
            if (num >= x) {
                if (num >= 9 * x) {
                    roman += ma[x];
                    roman += ma[10 * x];
                    num -= 9 * x;
                } else if (num < 5 * x && num >= 4 * x) {
                    roman += ma[x];
                    roman += ma[5 * x];
                    num -= 4 * x;
                } else {
                    if (num >= 5 * x) roman += ma[5 * x];
                    num %= (5 * x);
                    while (num >= x) {
                        roman += ma[x];
                        num -= x;
                    }
                }
            }
            x /= 10;
        }
        
        return roman;
    }
};

int main() {
    
    Solution so;
    string ans = so.intToRoman(47);
    
    cout << ans << endl;
    
    return 0;
}