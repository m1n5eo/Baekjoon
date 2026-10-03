#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

string str;
int result;

int main() {
    FASTIO

    while(cin >> str) result += 1;

    cout << result/5;
}