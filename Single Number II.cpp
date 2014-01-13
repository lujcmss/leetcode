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
private:
    long long calc(long long x, long long y) {
        y = abs(y);
        long long re = 0;
        long long three = 1;
        while (x != 0 || y != 0) {
            long long xx = x % 3;
            long long yy = y % 3;
            re += three * ((xx + yy) % 3);
            three *= 3;
            x /= 3;
            y /= 3;
        }
        return re;
    }
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        long long re = 0;
        int ne = 0;
        for (int i = 0; i < n; i++) {
            re = calc(re, A[i]);
            if (A[i] < 0) ne++;
        }
        if (ne % 3 != 0) re *= -1;
        return (int)re;
    }
};

int main() {
    int a[30] = {43,16,45,89,45,-2147483648,45,2147483646,-2147483647,-2147483648,43,2147483647,-2147483646,-2147483648,89,-2147483646,89,-2147483646,-2147483647,2147483646,-2147483647,16,16,2147483646,43};
    
    Solution so;
    int ans = so.singleNumber(a, 25);
    
    cout << ans;
    
    return 0;
}