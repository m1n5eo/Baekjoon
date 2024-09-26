#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int func(int num) {
    int rtn = 1;

    for(int i = 0; i < 5; i++) {
        rtn *= num;
    }

    return rtn;
}

int main() {
    FASTIO

    int sum = 0;
    string num;

    cin >> num;

    for(auto nums : num) {
        sum += func(nums-'0');
    }

    cout << sum;
}