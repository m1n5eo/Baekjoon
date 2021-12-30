#include <bits/stdc++.h>
using namespace std;

int arr[50001], sort_arr[50001];

bool cmp(int a, int b) {
    return a < b;
}

int BinarySearch(int idx, int start, int end) {
    int middle = (start+end)/2;
    while(start <= middle && middle <= end) {
        if(arr[idx] == sort_arr[start]) return start;
        else if(arr[idx] == sort_arr[middle]) return middle;
        else if(arr[idx] == sort_arr[end]) return end;
        else {
            if(arr[idx] < sort_arr[middle]) {
                end = middle;
                middle = (start+end)/2;
            }
            else if(arr[idx] > sort_arr[middle]) {
                start = middle;
                middle = (start+end)/2;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sort_arr[i] = arr[i];
    }
    sort(sort_arr, sort_arr+n, cmp);
    for(int i = 0; i < n; i++) {
        printf("%d ", BinarySearch(i, 0, n-1));
    }
}