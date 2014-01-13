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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = (int)cost.size();
        for (int i = 0; i < n; i++) {
            gas[i] = gas[i] - cost[i];
        }
        int i = 0;
        while (i < n)
            if (gas[i] >= 0) {
                int now = gas[i];
                gas[i] = 0;
                int j = 1;
                while (j < n) {
                    if (gas[(i+j)%n] >= 0 || now + gas[(i+j)%n] >= 0) {
                        now += gas[(i+j)%n];
                        gas[(i+j)%n] = 0;
                    } else {
                        gas[(i+j)%n] += now;
                        break;
                    }
                    j++;
                }
                if (j == n) return i;
                i += j;
            } else {
                i++;
            }
        
        return -1;
    }
};

int main() {
    vector<int> gas;
    vector<int> cost;
    gas.push_back(1); gas.push_back(2); gas.push_back(3); gas.push_back(4);
    cost.push_back(3); cost.push_back(4); cost.push_back(1); cost.push_back(2);
    
    Solution so;
    int ans = so.canCompleteCircuit(gas, cost);
    
    cout << ans;
    
    return 0;
}