long long int f(long long int num) {
    long long int dap = 0;
    while(num != 0) {
        dap = dap * 10;
        dap = dap + num%10;
        num = num / 10;
    }
    return dap;
}