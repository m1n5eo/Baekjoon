int sqrt(long long int a) {
    int i;

        if(a == 0) return 0;
    for(i = 0; a >= 0; ++i) {
        a = a - (i*2)-1;
    }

    return i-1;
}