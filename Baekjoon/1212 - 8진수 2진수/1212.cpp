#include <bits/stdc++.h>
using namespace std;

int main() {
    int n[8] = {0, 1, 10, 11, 100, 101, 110, 111};
    char scan[333336];
    scanf("%s", scan);
    printf("%d", n[scan[0]-'0']);
    int len = strlen(scan);
    for(int i = 1; i < len; i++) printf("%03d", n[scan[i]-'0']);
}