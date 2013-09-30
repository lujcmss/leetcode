#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
using namespace std;

class Solution {
private:
    int ans, tmp;
    set<int> se;
    
    void solve(int x) {
        tmp++;
        se.erase(x);
        if (se.count(x+1)) solve(x+1);
        if (se.count(x-1)) solve(x-1);
    }
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        se.clear();
        for (int i = 0; i < num.size(); i++) {
            se.insert(num[i]);
        }
        
        ans = 0;
        for (int i = 0; i < num.size(); i++)
            if (se.count(num[i])) {
                tmp = 0;
                solve(num[i]);
                ans = max(ans, tmp);
            }
        
        return ans;
    }
};

int main() {
    vector <int> num(10);
    
    for (int i = 0; i < 10; i++) num[i] = 1;
    
    Solution so;
    int ans = so.longestConsecutive(num);
    cout << ans << endl;
}
