long long f(double x) {
    long long int t = (long long int)x;

    if(t > x) return x - 1;
    else return x;
}