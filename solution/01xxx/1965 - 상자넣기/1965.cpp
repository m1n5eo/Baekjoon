#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

int n, arr[MAX], LIS[MAX];

bool compare(int a, int b) {
    return a < b;
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        LIS[i] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] < arr[j]) {
                if(LIS[i]+1 > LIS[j]) {
                    LIS[j] = LIS[i]+1;
                }
            }
        }
    }
    
    sort(LIS, LIS+n, compare);

    cout << LIS[n-1];
}