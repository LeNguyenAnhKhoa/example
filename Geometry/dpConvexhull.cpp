vector<ii> line;
bool cmp(ii a, ii b, ii c){
    return (double)(c.se - b.se) / (b.fi - c.fi) > (double)(a.se - c.se) / (c.fi - a.fi);
}
void add(int a, int b){
    while(SZ(line) >= 2 && !cmp(line[SZ(line)-2], line.back(), ii(a, b)))line.pop_back();
    line.pb(a, b);
}
int cal(ii x, int a){
    return x.fi * a + x.se;
}

int get(int x){
    int l = 0, r = SZ(line) - 1, res = 0;
    while(l <= r){
        int mid = l + r >> 1;
        if(mid == SZ(line) - 1){
            res = mid;
            break;
        }
        /// return max(y) <=> cal(line[mid], x) > cal(line[mid+1], x)
        /// return min(y) <=> cal(line[mid], x)  cal(line[mid+1], x)
        if(cal(line[mid], x) > cal(line[mid+1], x))
            res = mid, r = mid - 1;
        else l = mid + 1;
    }
    return cal(line[res], x);
}
