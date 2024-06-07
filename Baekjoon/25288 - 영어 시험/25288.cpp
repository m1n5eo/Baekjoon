#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    string str;
    cin >> str;

    for(int i = 0; i < n; i++) {
        cout << str;
    }

    return 0;
}