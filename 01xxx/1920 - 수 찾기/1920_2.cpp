#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

int n, m, k, arr[MAX];

bool compare(int a, int b) {
    return a < b;
}

int main() {
    FASTIO
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n, compare);

    cin >> m;

    for(int i = 0; i < m; i++) {
        cin >> k;

        cout << binary_search(arr, arr+n, k) << "\n";
    }
}