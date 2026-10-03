#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n = 5, num, sum = 0;

    for(int _ = 0; _ < n; _++) {
        cin >> num;

        if(num < 40) num = 40;
        sum += num;
    }

    cout << sum/n;
}