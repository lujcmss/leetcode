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
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //return (int)(pow(x, 0.5)+1e-8);
        
        double re = 1.0*x/2;
        double last = x;
        while (fabs(last - re) > 1e-8) {
            last = re;
            re = (last*last+x)/2/last;
        }
        
        return (int)(re + 1e-8);
    }
};

int main() {
    int n = 1;
    
    Solution so;
    int ans = so.sqrt(n);
    
    cout << ans << endl;
    
    return 0;
}