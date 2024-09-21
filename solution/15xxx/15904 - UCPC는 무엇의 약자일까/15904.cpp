#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

string str, result = "UCPC";

int main() {
    FASTIO

    getline(cin, str);

    int str_size = str.size(), idx = 0;

    for(int i = 0; i < str_size; i++) {
        if(idx < 4 && str[i] == result[idx]) {
            idx += 1;
        }
    }

    if(idx == 4) cout << "I love UCPC";
    else cout << "I hate UCPC";
}