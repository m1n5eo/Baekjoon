#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    string str;

    while(getline(cin, str)) {
        cout << str << "\n";
    }

    return 0;
}