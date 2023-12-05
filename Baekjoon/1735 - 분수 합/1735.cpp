#include <iostream>
#include <queue>
using namespace std;

int main() {
    int a, b, n, m;
    cin >> a >> b;
    cin >> n >> m;

    int k = b*m;
    a = a*(k/b); b = b*(k/b);
    n = n*(k/m); m = m*(k/m);

    int ja = a+n, mo = k;
    int temp = ja>mo? mo:ja;

    priority_queue<int> sosu;
    for(int i = 1; i*i < temp; i++) {
        if(temp%i == 0) {
            sosu.push(i);
            sosu.push(temp/i);
        }
    }

    int sosuSize = sosu.size();
    for(int i = 0; i < sosuSize; i++) {
        if(ja%sosu.top() == 0 && mo%sosu.top() == 0) {
            ja = ja/sosu.top();
            mo = mo/sosu.top();
        }
        sosu.pop();
    }

    cout << ja << " " << mo;
}