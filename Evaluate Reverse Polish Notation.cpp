#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <vector>
using namespace std;

class Solution {
    public:
    int evalRPN(vector<string> &tokens) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (tokens.size() == 0) return 0;
        stack<int> s;
        while (!s.empty()) s.pop();
        
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(b+a);
            } else if (tokens[i] == "-") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(b-a);
            } else if (tokens[i] == "*") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(b*a);
            } else if (tokens[i] == "/") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(b/a);
            } else {
                string tmp = tokens[i];
                int x = atoi(tmp.c_str());
                s.push(x);
            }
        }
        
        return s.top();
    }
};

int main() {
    vector<string> input;
    input.push_back("-4");
    input.push_back("13");
    input.push_back("5");
    input.push_back("/");
    input.push_back("+");
    
    Solution so;
    int ans = so.evalRPN(input);
    
    cout << ans << endl;
    
    return 0;
}