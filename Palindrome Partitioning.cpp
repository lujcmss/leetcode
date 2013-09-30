#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> tmp;
    vector<vector<string> > ans;
    int ls;
    void cut(vector<vector<int> > &f, string &s, int st) {
        if (st == ls) {
            ans.push_back(tmp);
            return;
        }
        for (int i = st+1; i <= ls; i++)
            if (f[st][i]) {
                string tmps;
                tmps.clear();
                for (int j = st; j < i; j++) tmps.push_back(s[j]);
                tmp.push_back(tmps);
                cut(f, s, i);
                tmp.pop_back();
            }
    }
public:
    vector<vector<string> > partition(string s) {
        ans.clear();
        tmp.clear();
        
        ls = (int)s.length();
        vector<vector<int> > f(ls+1, vector<int>(ls+1));
        
        for (int l = 1; l <= ls; l++)
            for (int i = 0; i < ls-l+1; i++)
                if (s[i] == s[i+l-1] && (l <= 2 || f[i+1][i+l-1])) f[i][i+l] = 1;
                else f[i][i+l] = 0;
        
        cut(f, s, 0);
        return ans;
    }
};

int main() {
    string s1="aabb";
    Solution so;
    vector<vector<string> > ans = so.partition(s1);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
