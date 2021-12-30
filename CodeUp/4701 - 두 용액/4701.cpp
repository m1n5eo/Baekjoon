#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    int n, arr[100001];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr+n, compare);

    int StartPoint = 0, EndPoint = n-1, minimum = 2100000000, start_idx, end_idx;
    while(StartPoint < EndPoint) {
        if(minimum > abs(arr[StartPoint]+arr[EndPoint])) {
            minimum = abs(arr[StartPoint]+arr[EndPoint]);
            start_idx = StartPoint;
            end_idx = EndPoint;
        }
        if(arr[StartPoint]+arr[EndPoint] > 0) EndPoint--;
        else StartPoint++;
    }
    printf("%d %d", arr[start_idx], arr[end_idx]);
}