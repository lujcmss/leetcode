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

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
private:
    static bool cmp(const Interval &x, const Interval &y) {
        return (x.start < y.start);
    }
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<Interval> re;
        re.clear();
        
        if (intervals.size() == 0) return re;
        
        int l, r;
        l = intervals[0].start; r = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= r) {
                r = max(r, intervals[i].end);
            } else {
                Interval tmp(l, r);
                re.push_back(tmp);
                l = intervals[i].start;
                r = intervals[i].end;
            }
        }
        Interval tmp(l, r);
        re.push_back(tmp);
        
        return re;
    }
};

int main() {
    vector<Interval> inte;
    inte.clear();
    
    Interval *tmp;
    tmp = new Interval(1, 3); inte.push_back(*tmp);
    tmp = new Interval(15, 18); inte.push_back(*tmp);
    tmp = new Interval(8, 10); inte.push_back(*tmp);
    tmp = new Interval(2, 6); inte.push_back(*tmp);
    
    
    Solution so;
    vector<Interval> ans = so.merge(inte);
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].start << " " << ans[i].end << endl;
    
    return 0;
}