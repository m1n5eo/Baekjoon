#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO
    
    string str;
    int n;

    cin >> str;
    cin >> n;

    cout << str[n-1];
}