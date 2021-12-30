int f() {
    int maxnum = 1, max = -1;
    for(int i = 0; i < n; i++) {
        if(max < d[i]) {
            max = d[i];
            maxnum = i;
        }
    }
    return maxnum + 1;
}