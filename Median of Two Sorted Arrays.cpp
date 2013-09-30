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
    double findm(int *a, int alow, int aup, int *b, int blow, int bup, int k) {
        if (alow == aup) return b[blow + k];
        if (blow == bup) return a[alow + k];
        if (k == 0) return min(a[alow], b[blow]);
        
        int l1 = (k+1)/2;
        int l2 = (k+1)/2+(k+1)%2;
        
        if (l1 > aup - alow) {
            l1 = aup - alow;
            l2 = k - l1;
        }
        if (l2 > bup - blow) {
            l2 = bup - blow;
            l1 = k - l2;
        }
        
        if (a[alow + l1 - 1] < b[blow + l2 - 1]) return findm(a, alow + l1, aup, b, blow, bup, k - l1);
        else return findm(a, alow, aup, b, blow + l2, bup, k - l2);
    }
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (m + n == 0) return 0;
        
        if ((m+n) % 2) return findm(A, 0, m, B, 0, n, (m+n)/2);
        else return (findm(A, 0, m, B, 0, n, (m+n)/2) + findm(A, 0, m, B, 0, n, (m+n)/2 - 1)) / 2;
    }
};

int main() {
    int a[20] = {1, 3, 4, 5, 7, 9};
    int b[20] = {2, 2, 3, 3, 8, 9};
    
    Solution so;
    double ans = so.findMedianSortedArrays(a, 0, b, 0);
    
    cout << ans << endl;
    
    return 0;
}