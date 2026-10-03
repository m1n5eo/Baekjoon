#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, cnt0 = 0, cnt1 = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        if(m) cnt1++;
        else cnt0++;
    }
    if(cnt0 > cnt1) printf("Junhee is not cute!");
    else printf("Junhee is cute!");
}
