/// return max(y) <=> "<="
/// return min(y) <=> ">="
bool cmp(ii a, ii b, ii c){
    return (double)(b.se - a.se) / (a.fi - b.fi) <= (double)(c.se - a.se) / (double)(a.fi - c.fi);
}
void add(int a, int b, int i){
    while(SZ(line) >= 2 && cmp(line[SZ(line)-2], line.back(), ii(a, b)))line.pop_back();
    line.pb(a, b);
    id.pb(i);
}
int cal(ii x, int a){
    return x.fi * a + x.se;
}
ii get(int x){
    int l = 0, r = SZ(line) - 1, res = 0;
    while(l < r){
        int mid = l + r >> 1;
        if(mid == SZ(line) - 1){
            res = mid;
            break;
        }
        /// return max(y) <=> cal(line[mid], x) > cal(line[mid+1], x)
        /// return min(y) <=> cal(line[mid], x) < cal(line[mid+1], x)
        if(cal(line[mid], x) > cal(line[mid+1], x))
            res = mid, r = mid;
        else l = mid + 1;
    }
    return ii(cal(line[res], x), id[res]);
}
