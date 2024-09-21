#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int n, arr[111111];

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    for(int i = 0; i < n; i++) {
        if(i == 0 || arr[i-1] != arr[i]) {
            cout << arr[i] << " ";
        }
    }

    return 0;
}