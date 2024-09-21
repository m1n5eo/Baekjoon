#include <iostream>
using namespace std;

struct point {
    long long int x, y, z;
};

int ccw(point a, point b, point c) {
    long long int CrossProduct = (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);

    if(CrossProduct < 0) return -1;
    else if(CrossProduct > 0) return 1;
    else return 0;
}

int main() {
    point a, b, c, d;

    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;

    int ccw1 = ccw(a, b, c);
    int ccw2 = ccw(a, b, d);

    int ccw3 = ccw(c, d, a);
    int ccw4 = ccw(c, d, b);

    if(ccw1*ccw2 < 0 && ccw3*ccw4 < 0) cout << 1;
    else cout << 0;

    return 0;
}