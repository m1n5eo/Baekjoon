#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    char ch[22];
    scanf("%d", &t);
    for(int testcase = 0; testcase < t; testcase++) {
        scanf("%d", &n);
        scanf("%s", ch);
        int len = strlen(ch);
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < n; j++) {
                printf("%c", ch[i]);
            }
        }
        printf("\n");
    }
}
