const int N = 1e5 + 5;
int n, f[17][N], a[N];

void init(){
    for(int i = 1;i <= n;++i)f[0][i] = a[i];
    for(int i = 1;1<<i <= n;++i)for(int j = 1;j + (1<<i) - 1 <= n;++j)
        f[i][j] = min(f[i-1][j], f[i-1][j+(1<<(i-1))]);
}

int get(int l,int r){
    int LOG = log2(r - l + 1);
    return min(f[LOG][l], f[LOG][r-(1<<LOG)+1]);
}
