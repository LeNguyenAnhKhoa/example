struct BIT{
    int bit[100005];
    void update(int i,int x){
        for(;i <= 1e5;i += i&(-i))
            bit[i] += x;
    }
    int query(int i){
        int res = 0;
        for(;i > 0;i -= i&(-i))
            res += bit[i];
        return res;
    }
    int range(int l,int r){
        return query(r) - query(l-1);
    }
};
