#define FOR(i, l, r) for(int i = l;i <= r;++i)
const int N = 1e5 + 5;
const int M = 420;
int n, q, id[N], L[M], R[M], a[N], m, sum[M], bl;
void build(){
    bl = sqrt(n);
    m = (n-1)/bl + 1;
    FOR(i, 1, m){
        L[i] = R[i-1] + 1;
        R[i] = min(n, i * bl);
        FOR(j, L[i], R[i]){
            sum[i] += a[j];
            id[j] = i;
        }
    }
}
void upd(int l, int r, int x){
    FOR(i, id[l]+1, id[r]-1)
        sum[i] += x * bl;
    if(id[l] != id[r]){
        FOR(i, l, R[id[l]]){
            a[i] += x;
            sum[id[l]] += x;
        }
        FOR(i, L[id[r]], r){
            a[i] += x;
            sum[id[r]] += x;
        }
    }
    else{
        FOR(i, l, r){
            a[i] += x;
            sum[id[l]] += x;
        }
    }
}
int get(int l, int r){
    int res = 0;
    FOR(i, id[l]+1, id[r]-1)
        res += sum[i];
    if(id[l] != id[r]){
        FOR(i, l, R[id[l]])res += a[i];
        FOR(i, L[id[r]], r)res += a[i];
    }
    else FOR(i, l, r)res += a[i];
    return res;
}
