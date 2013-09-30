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
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> fac;
        
        fac.clear();
        fac.push_back(1);
        for (int i = 1; i <= n; i++)
            fac.push_back(fac[i-1] * i);
        
        string re = "";
        string remain = "";
        for (int i = 1; i <= n; i++) remain += i + '0';
        
        if (k == 0 || k > fac[n]) return re;
        for (int i = n; i > 0; i--) {
            int p = (k-1)/fac[i-1];
            
            re += remain[p];
            remain.erase(p, 1);
            
            k = (k-1)%fac[i-1]+1;
        }
        
        return re;
    }
};

int main() {
    int n = 0, k = 1;
    
    Solution so;
    string ans = so.getPermutation(n, k);
    
    cout << ans << endl;
    
    return 0;
}