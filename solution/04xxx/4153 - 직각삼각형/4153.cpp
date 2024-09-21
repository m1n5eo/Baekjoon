#include <bits/stdc++.h>
using namespace std;

int main() {
    int n[3];
    while(1) {
        for(int i = 0; i < 3; i++) scanf("%d", &n[i]);
        sort(n, n+3);
        if(n[0] == 0 && n[1] == 0 && n[2] == 0) break;
        else if(n[0]*n[0] + n[1]*n[1] == n[2]*n[2]) printf("right\n");
        else printf("wrong\n");
    }
}
