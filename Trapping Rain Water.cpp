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
    struct node {
        int h, low, index;
    };
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<node> s;
        int re;
        
        re = 0;
        while (!s.empty()) s.pop();
        for (int i = 0; i < n; i++) {
            if (s.empty()) {
                node tmp;
                tmp.h = A[i];
                tmp.low = 0;
                tmp.index = i;
                s.push(tmp);
            } else {
                node now = s.top();
                while (now.h <= A[i]) {
                    re += (now.h - now.low) * (i - now.index - 1);
                    s.pop();
                    if (s.empty()) break;
                    now = s.top();
                }

                node tmp;
                tmp.h = A[i];
                tmp.low = 0;
                tmp.index = i;
                if (!s.empty()) {
                    s.pop();
                    re += (A[i] - now.low) * (i - now.index - 1);
                    now.low = A[i];
                    s.push(now);
                }
                s.push(tmp);
            }
        }
        
        return re;
    }
};

int main() {
    int a[20] = {4,2,3,2,4,0,1,3,2,1,2,1};
    int n = 5;
    
    Solution so;
    int ans = so.trap(a, n);
    
    cout << ans << endl;
    
    return 0;
}