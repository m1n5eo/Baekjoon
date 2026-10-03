#include <iostream>
#include <utility>
#include <ostream>
#include <algorithm>
using namespace std;

void func(pair<long long int, long long int> a, pair<long long int, long long int> b, pair<long long int, long long int> c, pair<long long int, long long int> d) {
    long long int aa = a.first;
    long long int bb = a.second;
    long long int cc = b.first;
    long long int dd = b.second;

    long long int a1 = dd-bb;
    long long int b1 = aa-cc;
    long long int c1 = bb*(cc-aa)+aa*(bb-dd);

    aa = c.first;
    bb = c.second;
    cc = d.first;
    dd = d.second;

    long long int a2 = dd-bb;
    long long int b2 = aa-cc;
    long long int c2 = bb*(cc-aa)+aa*(bb-dd);

    long long int new_a1 = a1*a2;
    long long int new_b1 = b1*a2;
    long long int new_c1 = c1*a2;

    long long int new_a2 = -a2*a1;
    long long int new_b2 = -b2*a1;
    long long int new_c2 = -c2*a1;

    double res1 = (-((double)new_c1+(double)new_c2))/((double)new_b1+(double)new_b2);

    new_a1 = a1*b2;
    new_b1 = b1*b2;
    new_c1 = c1*b2;

    new_a2 = -a2*b1;
    new_b2 = -b2*b1;
    new_c2 = -c2*b1;

    double res2 = (-((double)new_c1+(double)new_c2))/((double)new_a1+(double)new_a2);

    cout << fixed;
    cout.precision(10);
    cout << "\n" << res2 << " " << res1;

    return;
}

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

        if(a <= d && c <= b) {
            cout << 1;
            
            if(a == d) {
                cout << "\n" << a.first << " " << a.second;
            }
            else if(b == c) {
                cout << "\n" << b.first << " " << b.second;
            }
        }
        else cout << 0;
    }
    else if(ABC == 0) {
        if(a > b) swap(a, b);

        if(a <= c && c <= b) {
            cout << 1;
            cout << "\n" << c.first << " " << c.second;
        }
        else cout << 0;
    }
    else if(ABD == 0) {
        if(a > b) swap(a, b);

        if(a <= d && d <= b) {
            cout << 1;
            cout << "\n" << d.first << " " << d.second;
        }
        else cout << 0;
    }
    else if(CDA == 0) {
        if(c > d) swap(c, d);

        if(c <= a && a <= d) {
            cout << 1;
            cout << "\n" << a.first << " " << a.second;
        }
        else cout << 0;
    }
    else if(CDB == 0) {
        if(c > d) swap(c, d);

        if(c <= b && b <= d) {
            cout << 1;
            cout << "\n" << b.first << " " << b.second;
        }
        else cout << 0;
    }
    else if(ABC*ABD < 0 && CDA*CDB < 0) {
        cout << 1;

        func(a, b, c, d);
    }
    else {
        cout << 0;
    }

    return 0;
}