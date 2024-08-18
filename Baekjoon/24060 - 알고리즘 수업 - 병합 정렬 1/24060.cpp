#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, k, cnt;

void merge(int* A, int p, int q, int r) {
    int i = p, j = q+1, t = 1;
    int tmp[r+2];

    while (i <= q && j <= r) {
        if (A[i] <= A[j]) tmp[t++] = A[i++];
        else tmp[t++] = A[j++];
    }
    while (i <= q) tmp[t++] = A[i++];
    while (j <= r) tmp[t++] = A[j++];

    i = p; t = 1;

    while (i <= r) {
        A[i++] = tmp[t++];

        if(++cnt == k) {
            cout << tmp[t-1];
        }
    }
}

void merge_sort(int* A, int p, int r) {
    if(p < r) {
        int q = (p+r)/2;

        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main() {
    FASTIO
    
    cin >> n >> k;

    int* arr;
    arr = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n-1);

    if(cnt < k) cout << -1;
}