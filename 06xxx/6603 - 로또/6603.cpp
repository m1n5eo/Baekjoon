#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n = 1;
vector<int> lotto(22, 0), v(22, 0);

void f(int idx, int end) {
    if(idx == 6) {
        for(int i = 0; i < 6; i++) {
            cout << lotto[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = end+1; i < n; i++) {
        lotto[idx] = v[i];
        f(idx+1, i);
    }
}

int main() {
    FASTIO

    while(true) {
        cin >> n;

        if(n == 0) {
            break;
        }

        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        f(0, -1);

        cout << "\n";
    }
}