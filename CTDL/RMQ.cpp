int n, jump[17][100005], a[100005];

void init(){
    for(int i = 1;i <= log2(n);++i)jump[0][i] = a[i];
    for(int i = 1;i <= 16;++i)for(int j = 1;j + (1<<i) - 1 <= n;++j)
        jump[i][j] = min(jump[i-1][j], jump[i-1][j+(1<<(i-1))]);
}

int get(int l,int r){
    int LOG = log2(r - l + 1);
    return min(jump[LOG][l], jump[LOG][r-(1<<LOG)+1]);
}
