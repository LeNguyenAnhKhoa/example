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
int n;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("c.inp","r",stdin);
    cin >> n; vector<Point> a(n); int t = 1;
    for(Point &i : a)cin >> i.x >> i.y;
    int low = min_element(a.begin(), a.end()) - a.begin();
    vector<int> f, hull{low};
    for(int i = 0;i < n;++i)if(a[i] != a[low])f.pb(i);
    sort(f.begin(), f.end(), [&](int u,int v){
        int t = ccw(a[low], a[u], a[v]);
        return t != 0 ? t > 0 : (a[u] - a[low]).norm() < (a[v] - a[low]).norm();
    });
    for(auto i : f){
        while(t > 1 && ccw(a[hull[t-2]], a[hull.back()], a[i]) <= 0)
            hull.pop_back(), t--;
        hull.pb(i), t++;
    }
}
