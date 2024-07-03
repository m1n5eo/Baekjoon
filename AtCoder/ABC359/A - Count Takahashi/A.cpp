#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, result;
string str = "Takahashi";

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        if(str == temp) {
            result += 1;
        }
    }

    cout << result;
}