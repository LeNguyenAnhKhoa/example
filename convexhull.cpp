#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
struct Point {
    int x, y;
    Point() { x = y = 0; }
    Point(int x, int y) : x(x), y(y) {}

    Point operator + (const Point& a) const { return Point(x+a.x, y+a.y); }
    Point operator - (const Point& a) const { return Point(x-a.x, y-a.y); }
    Point operator * (int k) const { return Point(x*k, y*k); }

    int operator * (const Point& a) const { return x*a.x + y*a.y; } // dot product
    int operator % (const Point& a) const { return x*a.y - y*a.x; } // cross product

    Point conj() { return Point(x, -y); }
    int norm() { return x*x + y*y; }

    bool operator <(const Point &a){
        return a.x == x ? y < a.y : x < a.x;
    }
    bool operator !=(const Point &a){
        return x != a.x || y != a.y;
    }
};
int ccw(Point a, Point b, Point c) {
    return (b - a) % (c - a);
}
int n, t;
vector<Point> hull, a;
void convexhull(){
    vector<Point> f;
    Point low = *(min_element(a.begin(), a.end()));
    hull.pb(low), t = 1;
    for(int i = 0;i < n;++i)if(a[i] != low)f.pb(a[i]);
    sort(f.begin(), f.end(), [&](Point u,Point v){
        int t = ccw(low, u, v);
        return t != 0 ? t > 0 : (u - low).norm() < (v - low).norm();
    });
    for(Point i : f){
        while(t > 1 && ccw(hull[t-2], hull.back(), i) <= 0)
            hull.pop_back(), t--;
        hull.pb(i), t++;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("c.inp","r",stdin);
    cin >> n; a.resize(n);
    for(Point &i : a)cin >> i.x >> i.y;
    convexhull();
}
