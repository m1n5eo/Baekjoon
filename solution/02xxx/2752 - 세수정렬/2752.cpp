#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[3];
    for(int i = 0; i < 3; i++) scanf("%d", &arr[i]);
    sort(arr, arr+3);
    for(int i = 0; i < 3; i++) printf("%d ", arr[i]);
}
