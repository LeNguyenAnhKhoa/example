#define int long long
const int INF = 2e18;
int mode;
struct Line{
    mutable int a, b; mutable double k;
    bool operator<(const Line &p)const{return mode ? k < p.k : a < p.a;}
};
struct ConvexHull{
    multiset<Line> s;
    double div(int x,int y){return 1.0 * x / y;}
    template<class T>bool isect(T x,T y) {
        if(y == s.end()){x->k = INF; return 0;}
        if(x->a == y->a) x->k = (x->b >= y->b ? INF : -INF);
        else x->k = div(x->b - y->b, y->a - x->a);
        return x->k >= y->k;
    }
    void add(int a,int b) {
        auto z = s.insert({a, b, 0}), x = z++, y = x;
        while(isect(x, z)) z = s.erase(z);
        if(x != s.begin() && isect(--x,y)) isect(x, s.erase(y));
        while((y = x) != s.begin() && isect(--x,y)) isect(x, s.erase(y));
    }
    int query(int x) {
        mode = 1;
        auto pos = s.lower_bound({0, 0, x});
        mode = 0;
        return pos->a * x + pos->b;
    }
}cht;
