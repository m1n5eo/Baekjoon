#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int t;

int main() {
    FASTIO

    cin >> t;

    for(int testcase = 1; testcase <= t; testcase++) {
        string str;
        int a, b;

        cin >> str >> a >> b;

        int strSize = str.size();

        for(int i = 0; i < a; i++) cout << str[i];
        for(int i = b; i < strSize; i++) cout << str[i];
        cout << "\n";
    }
}