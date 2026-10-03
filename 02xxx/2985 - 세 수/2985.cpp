#include <bits/stdc++.h>
using namespace std;

int main() {
    int n[4]; // 0 =    1 +    2 -     3 *     4 /
    scanf("%d %d %d", &n[0], &n[1], &n[2]);
    if(n[0] + n[1] == n[2]) printf("%d+%d=%d", n[0], n[1], n[2]);
    else if(n[0] - n[1] == n[2]) printf("%d-%d=%d", n[0], n[1], n[2]);
    else if(n[0] * n[1] == n[2]) printf("%d*%d=%d", n[0], n[1], n[2]);
    else if(n[0] / n[1] == n[2]) printf("%d/%d=%d", n[0], n[1], n[2]);
    else if(n[0] == n[1] + n[2]) printf("%d=%d+%d", n[0], n[1], n[2]);
    else if(n[0] == n[1] - n[2]) printf("%d=%d-%d", n[0], n[1], n[2]);
    else if(n[0] == n[1] * n[2]) printf("%d=%d*%d", n[0], n[1], n[2]);
    else if(n[0] == n[1] / n[2]) printf("%d=%d/%d", n[0], n[1], n[2]);
}
