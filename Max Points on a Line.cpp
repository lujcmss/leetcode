#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
private:
    map<pair<int, int>, int> lines;
    
    int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x%y);
    }
public:
    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (points.size() < 2) return (int)points.size();
        
        int re = 0;
        
        for (int i = 0; i < points.size(); i++) {
            lines.clear();
            int dup = 1;
            for (int j = i + 1; j < points.size(); j++)
                if (points[i].x == points[j].x && points[i].y == points[j].y) dup++;
            
            re = max(re, dup);
            for (int j = i + 1; j < points.size(); j++) {
                int dx = points[i].x - points[j].x;
                int dy = points[i].y - points[j].y;
                
                if (dx == 0 && dy == 0) continue;
                
                if (dx == 0) {
                    dy = 1;
                }
                if (dy < 0) {
                    dy *= -1;
                    dx *= -1;
                } else if (dy == 0) {
                    dx = 1;
                }
                
                if (dx != 0 && dy != 0) {
                    int g = gcd(abs(dx), abs(dy));
                    dx /= g;
                    dy /= g;
                }
                pair<int, int> p = make_pair(dx, dy);
                re = max(re, ++lines[p] + dup);
            }
        }
        return re;
    }
};

int main() {
    vector<Point> point;
    point.push_back(Point(0,0));
    point.push_back(Point(0,0));
    point.push_back(Point(0,0));
    //point.push_back(Point(-3,-3));
    
    Solution so;
    int ans = so.maxPoints(point);
    
    cout << ans << endl;
    
    return 0;
}