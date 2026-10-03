#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int a, b, arr[22], temp[22];

    for(int i = 1; i <= 20; i++) {
        arr[i] = i;
    }

    for(int i = 0; i < 10; i++) {
        cin >> a >> b;

        for(int j = a; j <= b; j++) {
            temp[j] = arr[j];
        }
        for(int j = a; j <= b; j++) {
            arr[j] = temp[a+b-j];
        }
    }

    for(int i = 1; i <= 20; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}