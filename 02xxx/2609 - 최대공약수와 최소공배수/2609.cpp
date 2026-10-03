#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a = n, b = m;
    if(n < m) {
        swap(n, m);
        swap(a, b);
    }
    while(m != 0) {
        n = n%m;
        swap(n, m);
    }
    printf("%d\n", n);

    for(int i = a; ; i+=a) {
        if(i%b == 0) {
            printf("%d", i);
            return 0;
        }
    }
}
