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

    priority_queue<int> pq;
    for(int i = 1; i*i < temp; i++) {
        if(temp%i == 0) {
            pq.push(i);
            pq.push(temp/i);
        }
    }

    int pqSize = pq.size();
    for(int i = 0; i < pqSize; i++) {
        if(ja%pq.top() == 0 && mo%pq.top() == 0) {
            ja = ja/pq.top();
            mo = mo/pq.top();
        }
        pq.pop();
    }

    cout << ja << " " << mo;
}