//https://en.wikipedia.org/wiki/Closest_pair_of_points_problem#Planar_case
template <class T> inline bool minn(T &A,T B){return A > B ? (A = B,1) : 0;}
#define ll long double
struct Point {
    ll x, y;
    Point() { x = y = 0; }
    Point(ll x, ll y) : x(x), y(y) {}

    Point operator + (const Point& a) const { return Point(x+a.x, y+a.y); }
    Point operator - (const Point& a) const { return Point(x-a.x, y-a.y); }
    Point operator * (ll k) const { return Point(x*k, y*k); }

    ll operator * (const Point& a) const { return x*a.x + y*a.y; } // dot product
    ll operator % (const Point& a) const { return x*a.y - y*a.x; } // cross product

    Point conj() { return Point(x, -y); }

    ll norm() { return x*x + y*y; }

    friend ll d(const Point &a,const Point &b){
        ll x = (a.x - b.x); x *= x;
        ll y = (a.y - b.y); y *= y;
        return sqrt(x + y);
    }

    bool operator <(const Point &a){
        return a.x == x ? y < a.y : x < a.x;
    }
    bool operator !=(const Point &a){
        return x != a.x || y != a.y;
    }
    bool operator ==(const Point &a){
        return x == a.x && y == a.y;
    }
}a[100005], b[100005];
ll cal(int l,int r){
    if(r - l <= 4){
        ll res = 1e18;
        for(int i = l;i < r;++i)for(int j = i+1;j <= r;++j)
            minn(res, d(a[i], a[j]));
        return res;
    }
    int mid = l + r >> 1;
    ll res = min(cal(l, mid), cal(mid+1, r));
    while(l < mid && a[mid].y - a[l].y > res)l++;
    while(r > mid && a[r].y - a[mid].y > res)r--;
    for(int i = l;i <= r;++i)b[i] = a[i];
    sort(b + l, b + r + 1);
    for(int i = l, j = l;i < r;++i){
        while(j <= r && b[i].x - b[j].x > res)j++;
        for(int k = j;k <= r && b[k].x <= b[i].x + res;++k)
            if(i != k)minn(res, d(b[k], b[i]));
    }
    return res;
}
