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
    double re;
    
    double po(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        
        double tmp = po(x, n/2);
        if (n%2) return tmp*tmp*x;
        else return tmp*tmp;
    }
    
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (n >= 0) re = po(x, n);
        else re = 1 / po(x, -n);
        
        return re;
    }
};

int main() {
    double x = 1.5;
    int n = 3;
    
    Solution so;
    double ans = so.pow(x, n);
    
    cout << ans << endl;
    
    return 0;
}