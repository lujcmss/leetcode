#include <stdio.h>
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
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> st;
        stack<int> index;
        
        int maxn = 0;
        for (int i = 0; i < height.size(); i++) {
            if (i == 0 || height[i] > st.top()) {
                st.push(height[i]);
                index.push(i);
            } else {
                int last;
                while (!st.empty() && height[i] <= st.top()) {
                    last = index.top();
                    maxn = max(maxn, st.top() * (i - index.top()));
                    st.pop();
                    index.pop();
                }
                st.push(height[i]);
                if (!index.empty()) index.push(last);
                else index.push(0);
            }
        }
        
        while (!st.empty()) {
            maxn = max(maxn, st.top() * ((int)height.size() - index.top()));
            st.pop();
            index.pop();
        }

        return maxn;
    }
};

int main() {
    vector<int> height(6);
    height[0] = 10; height[1] = 2; height[2] = 0;
    height[3] = 3; height[4] = 2; height[5] = 5;
    
    Solution so;
    int ans = so.largestRectangleArea(height);
    
    cout << ans << endl;
    return 0;
}