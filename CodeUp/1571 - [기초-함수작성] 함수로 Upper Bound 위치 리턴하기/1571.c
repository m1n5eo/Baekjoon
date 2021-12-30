int upper_bound(int a) {
    for(int i = 1; i <= n; i++) {
        if(a < d[i]) return i;
    }
    return n+1;
}