/// fi > 0
vector<ii> line;
/// return max(y) <=> ">="
/// return min(y) <=> "<="
bool cmp(ii a, ii b, ii c){
    return (double)(b.se - a.se)/(a.fi - b.fi) >= (double)(a.se - c.se) / (c.fi - a.fi);
}
void add(int a, int b){
    while(SZ(line) >= 2 && cmp(line[SZ(line)-2], line.back(), ii(a, b)))line.pop_back();
    line.pb(a, b);
}
int cal(ii x, int a){
    return x.fi * a + x.se;
}
int get(int x){
    if(line.empty())return -1e18;
    int l = 0, r = SZ(line) - 1, res = 0;
    while(l < r){
        int mid = l + r >> 1;
        /// return max(y) <=> cal(line[mid], x) > cal(line[mid+1], x)
        /// return min(y) <=> cal(line[mid], x) < cal(line[mid+1], x)
        if(cal(line[mid], x) >= cal(line[mid+1], x))r = mid;
        else l = mid + 1;
    }
    return cal(line[l], x);
}
