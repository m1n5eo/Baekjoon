#include <bits/stdc++.h>
using namespace std;

int arr[111][111];

int main() {
    int x1, y1, x2, y2;
    for(int t = 0; t < 4; t++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(int i = x1; i < x2; i++) {
            for(int j = y1; j < y2; j++) {
                arr[i][j] = 1;
            }
        }
    }

    int sum = 0;#include <bits/stdc++.h>
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

    for(int i = 0; i < 102; i++) {
        for(int j = 0; j < 102; j++) {
            if(arr[i][j]) sum++;
        }
    }
    printf("%d", sum);
}
