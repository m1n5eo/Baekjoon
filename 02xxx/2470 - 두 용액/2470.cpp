#include <bits/stdc++.h>
using namespace std;

int n, idxStart, idxEnd, saveStart, saveEnd;
int minPlus = 2100000000, arr[100001];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int StartPoint = 0, EndPoint = n-1;
    while(StartPoint < EndPoint) {
        if(minPlus > abs(arr[StartPoint]+arr[EndPoint])) {
            minPlus = abs(arr[StartPoint]+arr[EndPoint]);
            saveStart = StartPoint;
            saveEnd = EndPoint;
        }
        if(arr[StartPoint]+arr[EndPoint] > 0) EndPoint--;
        else StartPoint++;
    }
    cout << arr[saveStart] << " " << arr[saveEnd];
}