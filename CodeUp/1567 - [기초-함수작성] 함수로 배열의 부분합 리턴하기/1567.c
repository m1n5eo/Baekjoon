long long int subsetsum(int x, int y) {
    long long int sum = 0;
    for(int i = x; i <= y; i++) {
        sum = sum + d[i];
    }
    return sum;
}