#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int n, m, cntMin = 1234567890;
    char pan[51][51];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%s", pan[i]);
    for(int i = 0; i < n-7; i++) {
        for(int j = 0; j < m-7; j++) {
            int cnt1 = 0, cnt2 = 0;
            for(int x = i; x < i+8; x++) {
                for(int y = j; y < j+8; y++) {
                    if((x+y)%2 == 0 && pan[x][y] == 'W') cnt1++;
                    if((x+y)%2 == 0 && pan[x][y] == 'B') cnt2++;
                    if((x+y)%2 == 1 && pan[x][y] == 'W') cnt2++;
                    if((x+y)%2 == 1 && pan[x][y] == 'B') cnt1++;
                }
            }
            cntMin = min(cntMin, cnt1);
            cntMin = min(cntMin, cnt2);
        }
    }
    printf("%d", cntMin);
}