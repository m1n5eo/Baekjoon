bool prime(int k) {
    int i;
    for(i = 2; i < k; i++) {
        if(k % i == 0) {
            break;
        }
    }
    return i == k;
}