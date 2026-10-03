#include <bits/stdc++.h>
using namespace std;

int n;
int startSave = 0, endSave= n-1, minSum = 2100000000;
int arr[100001];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int startPoint = 0, endPoint = n-1;
    while(startPoint < endPoint) {
        if(abs(arr[startPoint]+arr[endPoint]) < minSum) {
            minSum = abs(arr[startPoint]+arr[endPoint]);
            startSave = startPoint; endSave = endPoint;
        }
        if(arr[startPoint]+arr[endPoint] < 0) startPoint++;
        else endPoint--;
    }
    printf("%d %d", arr[startSave], arr[endSave]);
}