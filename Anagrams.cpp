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
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> re;
        re.clear();
        
        map<string, int> ma;
        vector<int> choose(strs.size());
        ma.clear();
        
        for (int i = 0; i < strs.size(); i++) {
            choose[i] = 0;
            string s = strs[i];
            sort(s.begin(), s.end());
            
            if (ma.count(s)) {
                choose[i] = 1;
                choose[ma[s]] = 1;
            } else {
                ma.insert(make_pair(s, i));
            }
        }
        
        for (int i = 0; i < strs.size(); i++)
            if (choose[i]) re.push_back(strs[i]);
        
        return re;
    }
};

int main() {
    vector<string> str;
    //str.push_back("ate");
    //str.push_back("et");
    //str.push_back("asdf");
    //str.push_back("adf");
    str.push_back("asd");
    
    Solution so;
    vector<string> ans = so.anagrams(str);
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    
    return 0;
}