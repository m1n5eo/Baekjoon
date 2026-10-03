#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

struct coordinate {
    lli x1, y1, x2, y2;
};

int main() {
    FASTIO

    coordinate a, b, m;

    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

    if(a.x1 > a.x2) swap(a.x1, a.x2);
    if(a.y1 > a.y2) swap(a.y1, a.y2);
    if(b.x1 > b.x2) swap(b.x1, b.x2);
    if(b.y1 > b.y2) swap(b.y1, b.y2);

    m.x1 = min(min(a.x1, b.x1), min(a.x2, b.x2));
    m.y1 = min(min(a.y1, b.y1), min(a.y2, b.y2));
    m.x2 = max(max(a.x1, b.x1), max(a.x2, b.x2));
    m.y2 = max(max(a.y1, b.y1), max(a.y2, b.y2));

    if(a.x2-a.x1 + b.x2-b.x1 == m.x2-m.x1 && a.y2-a.y1 + b.y2-b.y1 == m.y2-m.y1) cout << "POINT";
    else if(a.x2-a.x1 + b.x2-b.x1 == m.x2-m.x1 && a.y2-a.y1 + b.y2-b.y1 > m.y2-m.y1) cout << "LINE";
    else if(a.x2-a.x1 + b.x2-b.x1 > m.x2-m.x1 && a.y2-a.y1 + b.y2-b.y1 == m.y2-m.y1) cout << "LINE";
    else if(a.x2-a.x1 + b.x2-b.x1 > m.x2-m.x1 && a.y2-a.y1 + b.y2-b.y1 > m.y2-m.y1) cout << "FACE";
    else cout << "NULL";
}