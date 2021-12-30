int gcd(int n, int m) {
    int temp;
    if(n > m) {
        temp = n;
        n = m;
        m = temp;
    }

    for(int i = n; i >= 1; i--) {
        if(n % i == 0 && m % i == 0) return i;
    }
}