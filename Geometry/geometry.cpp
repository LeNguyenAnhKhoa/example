#define ll long long
struct Point {
    ll x, y;
    Point() { x = y = 0; }
    Point(ll x, ll y) : x(x), y(y) {}

    Point operator + (const Point& a) const { return Point(x+a.x, y+a.y); }
    Point operator - (const Point& a) const { return Point(x-a.x, y-a.y); }
    Point operator * (ll k) const { return Point(x*k, y*k); }

    int operator * (const Point& a) const { return x*a.x + y*a.y; } // dot product
    int operator % (const Point& a) const { return x*a.y - y*a.x; } // cross product

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
};


///left: ccw > 0
///right: ccw < 0
int ccw(Point a, Point b, Point c) {
    return (b - a) % (c - a);
}

int S(Point a, Point b, Point c){
    return abs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) / 2;
}
