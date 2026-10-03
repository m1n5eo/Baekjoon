#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, arr[5];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < 5; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < 5; i++) printf("%d ", arr[i]-n*m);
}
