#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
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
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = (int)ratings.size();
        
        vector<int> num;
        num.clear();
        num.resize(n+1);
        
        num[0] = 1;
        for (int i = 0; i < n - 1; i++)
            if (ratings[i] >= ratings[i+1]) {
                num[i+1] = 1;
            } else {
                num[i+1] = num[i] + 1;
            }
        
        for (int i = n - 2; i >= 0; i--)
            if (ratings[i] > ratings[i+1]) {
                num[i] = max(num[i], num[i+1] + 1);
            }
        
        int re = 0;
        for (int i = 0; i < n; i++) re += num[i];
        
        return re;
    }
};

int main() {
    vector<int> ratings;
    ratings.push_back(1);
    ratings.push_back(2);
    ratings.push_back(3);
    ratings.push_back(2);
    /*ratings.push_back(3);
    ratings.push_back(2);
    ratings.push_back(1);*/
    
    Solution so;
    int ans = so.candy(ratings);
    
    cout << ans;
    
    return 0;
}