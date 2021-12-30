int maxi(int n, int m) {
    int maxindex;
    long long int max = -2147483648;
    for(int i = n; i <= m; i++) {
        if(max < d[i]) {
            max = d[i];
            maxindex = i;
        }
    }
    return maxindex;
}