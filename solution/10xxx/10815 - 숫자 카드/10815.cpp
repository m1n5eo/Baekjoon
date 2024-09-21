#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, card1[500001], card2;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &card1[i]);
    sort(card1, card1+n);

    scanf("%d", &m);
    for(int t = 0; t < m; t++) {
        scanf("%d", &card2);
        int left = 0, right = n-1, dap = 0;
        while(left <= right) {
            int mid = (left+right)/2;
            if(card1[mid] == card2) {
                dap = 1;
                break;
            }
            else if(card2 < card1[mid]) right = mid-1;
            else if(card2 > card1[mid]) left = mid+1;
        }
        printf("%d ", dap);
    }
}
