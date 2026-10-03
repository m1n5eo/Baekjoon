#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int sum = 300, temp;

int main() {
    FASTIO

    for(int i = 0; i < 4; i++) {
        cin >> temp;
        sum += temp;
    }

    cout << (sum <= 1800? "Yes" : "No");
}