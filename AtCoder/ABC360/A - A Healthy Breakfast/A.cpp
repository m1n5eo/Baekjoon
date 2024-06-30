#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    string str;
    cin >> str;

    if(str[0] == 'R') cout << "Yes";
    else if(str[1] == 'R' && str[2] == 'M') cout << "Yes";
    else cout << "No";
}