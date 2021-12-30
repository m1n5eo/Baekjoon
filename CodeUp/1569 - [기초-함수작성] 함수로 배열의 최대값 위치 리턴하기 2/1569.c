int findi(int num) {
    for(int i = 1; i <= n; i++) {
        if(d[i] == num) return i;
    }
    return -1;
}