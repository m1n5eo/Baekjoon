long long int pow(int b, int m) {
    long long int result = 1;
    if(b == 1) result = 1;
    else {
        for(int i = 0; i < n; i++) result *= b;
    }
    return result;
}