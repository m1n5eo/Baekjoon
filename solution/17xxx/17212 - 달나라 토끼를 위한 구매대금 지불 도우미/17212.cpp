#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

int main() {
    FASTIO
    
    int n, coin[MAX] = {0, 1, 1, 2, 2, 1, 2, };

    for(int i = 7; i < MAX; i++) {
        coin[i] = min(min(coin[i-1], coin[i-2]), min(coin[i-5], coin[i-7]))+1;
    }

    cin >> n;
    cout << coin[n];
}