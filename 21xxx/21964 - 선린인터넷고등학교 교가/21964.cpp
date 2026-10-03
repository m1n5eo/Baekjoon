#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int len;
    string str;

    cin >> len;
    cin >> str;

    for(int i = len-5; i < len; i++) {
        cout << str[i];
    }
}