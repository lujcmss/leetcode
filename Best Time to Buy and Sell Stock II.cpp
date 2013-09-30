#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (prices.size() == 0) return 0;
        
        int ans = 0;
        for (int i = 1; i < prices.size(); i++)
            if (prices[i] > prices[i-1]) ans += prices[i] - prices[i-1];
            
        return ans;
    }
};

int main() {
    vector<int> price;
    price.clear();
    for (int i = 0; i < 10; i++) price.push_back(i);
    
    Solution so;
    int ans = so.maxProfit(price);
    cout << ans;
}
