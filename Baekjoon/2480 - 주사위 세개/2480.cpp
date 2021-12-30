#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a == b && b == c) printf("%d", 10000+a*1000);
    else if(a == b || a == c) printf("%d", 1000+a*100);
    else if(b == c) printf("%d", 1000+b*100);
    else if(a != b && b != c && c != a) printf("%d", max(#include <stdio.h>

int main() {
    int cnt, arr;
    for(int i = 0; i < 3; i++) {
        cnt = 0;
        for(int j = 0; j < 4; j++) {
            scanf("%d", &arr);
            if(arr == 0) cnt = cnt + 1;
        }
        if(cnt == 1) printf("A\n");
        else if(cnt == 2) printf("B\n");
        else if(cnt == 3) printf("C\n");
        else if(cnt == 4) printf("D\n");
        else if(cnt == 0) printf("E\n");
    }
}
a, max(b, c))*100);
}
