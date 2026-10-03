#include <iostream>
#include <utility>
using namespace std;

int ccw(pair<long long int, long long int> a, pair<long long int, long long int> b, pair<long long int, long long int> c) {
    long long int CrossProduct = (b.first-a.first)*(c.second-a.second) - (c.first-a.first)*(b.second-a.second);

    if(CrossProduct < 0) return -1;
    else if(CrossProduct > 0) return 1;
    else return 0;
}

int main() {
    pair<long long int, long long int> a, b, c, d;

    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;
    cin >> d.first >> d.second;

    int ABC = ccw(a, b, c);
    int ABD = ccw(a, b, d);
    int CDA = ccw(c, d, a);
    int CDB = ccw(c, d, b);

    if(ABC == 0 && ABD == 0 && CDA == 0 && CDB == 0) {
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);

        if(a <= d && c <= b) cout << 1;
        else cout << 0;
    }
    else if(ABC == 0) {
        if(a > b) swap(a, b);

        if(a <= c && c <= b) cout << 1;
        else cout << 0;
    }
    else if(ABD == 0) {
        if(a > b) swap(a, b);

        if(a <= d && d <= b) cout << 1;
        else cout << 0;
    }
    else if(CDA == 0) {
        if(c > d) swap(c, d);

        if(c <= a && a <= d) cout << 1;
        else cout << 0;
    }
    else if(CDB == 0) {
        if(c > d) swap(c, d);

        if(c <= b && b <= d) cout << 1;
        else cout << 0;
    }
    else if(ABC*ABD < 0 && CDA*CDB < 0) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}