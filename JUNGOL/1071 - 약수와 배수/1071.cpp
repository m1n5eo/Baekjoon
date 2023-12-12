#include <iostream>
using namespace std;

int main() {
    int n, arr[44];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m, sum1 = 0, sum2 = 0;
    cin >> m;
    for(int i = 0; i < n; i++) {
        if(m%arr[i] == 0) sum1 += arr[i];
        if(arr[i]%m == 0) sum2 += arr[i];
    }
    cout << sum1 << "\n" << sum2;
}