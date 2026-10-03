#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define pll pair<lli, lli>

int main() {
    FASTIO

    int n, mode;
    lli temp;
    pll now = {0, 0};

    cin >> n;

    for(int _ = 0; _ < n; _++) {
        cin >> mode;

        if(mode == 1) {
            cin >> temp;
            now = {now.first + temp, now.second ^ temp};
        }
        else if(mode == 2) {
            cin >> temp;
            now = {now.first - temp, now.second ^ temp};
        }
        else if(mode == 3) {
            cout << now.first << "\n";
        }
        else if(mode == 4) {
            cout << now.second << "\n";
        }
    }
}