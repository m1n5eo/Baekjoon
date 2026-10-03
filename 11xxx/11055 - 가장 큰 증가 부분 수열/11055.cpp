#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    scanf("%d", &n);
    vector <int> arr;
    vector <int> LIS;
    vector <int> dap;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        arr.push_back(a);
        LIS.push_back(1);
        dap.push_back(a);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i] < arr[j]) {
                LIS[j] = LIS[j]+1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(dap[i] < arr[i] + dap[j] && LIS[i] > LIS[j]) dap[i] = arr[i]+dap[j];
        }
    }
    sort(dap.begin(), dap.end());
    printf("%d", dap[n-1]);

    // for(int i = 0; i < n; i++) printf("%3d : %2d : %3d\n", arr[i], LIS[i], dap[i]);
}
