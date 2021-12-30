long long int f (int num) {
    long long int dap = 1;
    for(int i = 2; i <= num; i++) {
        dap = dap * i;
    }
    return dap;
}