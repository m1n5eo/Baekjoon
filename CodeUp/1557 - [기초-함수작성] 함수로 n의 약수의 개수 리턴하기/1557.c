int f (int num) {
    int cnt = 1;
    for(int i = 2; i <= num; i++) {
        if(num % i == 0) {
            cnt = cnt + 1;
        }
    }
    return cnt;
}