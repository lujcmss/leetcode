#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> re;
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        re.clear();
        
        for (int i = 0; i < (1<<n); i++) re.push_back(i^(i>>1));
        
        return re;
    }
};

int main() {
    int n = 2;
    
    Solution so;
    vector<int> ans = so.grayCode(n);
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    
    return 0;
}