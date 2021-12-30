long long int lcd(int n, int m) {
    int dirtn  = gcd(n, m);
    return ((long long int)n / gcd(n,m)) * (long long int)m;
}