int f(int num) {
    for(int i = 1; i <= n; i++) {
        if(num == d[i]) return i;
    }
    return -1;
}