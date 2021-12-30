void f(int k) {
    int cnt = 0;
    for(int i = 2; i < k; i++) {
        if(k % i == 0) cnt = cnt + 1;
    }
    if(cnt != 0) printf("composite");
    else if(cnt == 0) printf("prime");
}