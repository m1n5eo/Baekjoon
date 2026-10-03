#include <iostream>
using namespace std;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    long long int CrossProduct = (b.first-a.first)*(c.second-a.second) - (c.first-a.first)*(b.second-a.second);

    if(CrossProduct < 0) return -1;
    else if(CrossProduct > 0) return 1;
    else return 0;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    pair<int, int> a, b, c, d;

    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;
    cin >> d.first >> d.second;

    int ABC = ccw(a, b, c);
    int ABD = ccw(a, b, d);
    int CDA = ccw(c, d, a);
    int CDB = ccw(c, d, b);

    if(ABC*ABD < 0 && CDA*CDB < 0) cout << 1;
    else cout << 0;

    return 0;
}