#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int h1, m1, s1;
    int h2, m2, s2;
    char ignore1, ignore2;

    cin >> h1 >> ignore1 >> m1 >> ignore2 >> s1;
    cin >> h2 >> ignore1 >> m2 >> ignore2 >> s2;

    int total1 = h1*3600 + m1*60 + s1;
    int total2 = h2*3600 + m2*60 + s2;

    int res = 0;

    if(total1 < total2) {
        res = total2-total1;
    }
    else {
        res = total2+86400-total1;
    }

    cout << setw(2) << setfill('0') << res/3600 << ':';
    cout << setw(2) << setfill('0') << (res-res/3600*3600)/60 << ':';
    cout << setw(2) << setfill('0') << (res-res/60*60);
}