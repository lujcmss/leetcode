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
    int close;
    int sum;
public:
    int threeSumClosest(vector<int> &num, int target)  {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        close = ~0U>>1;
        sum = 0;
        
        for (int i = 0; i < num.size(); i++) {
            if (i != 0 && num[i] == num[i-1]) continue;
            int l = i + 1;
            int r = (int)num.size() - 1;
            
            while (l < r) {
                if (abs(num[l] + num[r] + num[i] - target) < close) {
                    close = abs(num[l] + num[r] + num[i] - target);
                    sum = num[l] + num[r] + num[i];
                } else if (num[l] + num[r] + num[i] <= target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return sum;
    }
};

int main() {
    vector<int> num;
    num.push_back(-1);
    num.push_back(0);
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    //num.push_back(-4);
    
    Solution so;
    int ans = so.threeSumClosest(num, -2);
    
    cout << ans;

    return 0;
}