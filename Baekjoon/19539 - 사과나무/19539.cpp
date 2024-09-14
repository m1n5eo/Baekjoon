#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, tree, sum = 0, cnt = 0;
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> tree;

        sum += tree;
        cnt += tree/2;
    }

    if(sum%3 != 0) cout << "NO";
    else if(sum/3 > cnt) cout << "NO";
    else cout << "YES";
}