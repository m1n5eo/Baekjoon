void myswap(int *n, int* m) {
    int t;
    if(*n > *m) {
        t = *n;
        *n = *m;
        *m = t;
    }
}