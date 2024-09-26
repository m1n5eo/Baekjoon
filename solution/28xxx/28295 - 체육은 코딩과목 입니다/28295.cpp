#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int t, res = 40;
    char prt[4] = {'N', 'E', 'S', 'W'};

    for(int i = 0; i < 10; i++) {
        cin >> t;

        if(t == 1) res += 1;
        else if(t == 2) res += 2;
        else if(t == 3) res -= 1;
    }

    cout << prt[res%4];
}