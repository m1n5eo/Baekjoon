#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t, arr[11];
    cin >> t;

    for(int testcase = 0; testcase < t; testcase++) {
        for(int i = 0; i < 10; i++) {
            cin >> arr[i];
        }
        sort(arr, arr+10);
        cout << arr[7] << endl;
    }
}