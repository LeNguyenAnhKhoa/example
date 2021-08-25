int n, jump[18][100005], a[100005];

void init(){
    for(int i = 0;i < n;++i)jump[0][i] = a[i];
    for(int i = 1;1<<i <= n;++i)for(int j = 0;j + (1<<i) - 1 < n;++j)
        jump[i][j] = min(jump[i-1][j], jump[i-1][j+(1<<(i-1))]);
}

int query(int l,int r){
    int LOG = log2(r - l + 1);
    return min(jump[LOG][l], jump[LOG][r-(1<<LOG)+1]);
}
