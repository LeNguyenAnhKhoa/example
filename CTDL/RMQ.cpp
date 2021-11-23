#define FOR(i, l, r) for(int i = l;i <= r;++i)
const int N = 1e5 + 5;
int n, f[17][N], a[N];

void init(){
    FOR(i, 1, n)f[0][i] = a[i];
    FOR(i, 1, log2(n))FOR(j, 1, n-(1<<i)+1)
        f[i][j] = min(f[i-1][j], f[i-1][j+(1<<(i-1))]);
}

int get(int l, int r){
    int LOG = log2(r - l + 1);
    return min(f[LOG][l], f[LOG][r-(1<<LOG)+1]);
}
