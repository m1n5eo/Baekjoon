long long int f() {
    int min = d[1];
    for(int i = 2; i <= n; i++) {
        if(min > d[i]) {
            min = d[i];
        }
    }
    return min;
}