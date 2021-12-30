#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[6], cal[6] = {1, 1, 2, 2, 2, 8};
    for(int i = 0; i < 6; i++) {
        scanf("%d", &arr[i]);
        printf("%d ", cal[i]-arr[i]);
    }
}
